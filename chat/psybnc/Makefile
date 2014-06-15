# $NetBSD: Makefile,v 1.1 2014/06/15 21:55:17 pettai Exp $
#

DISTNAME=	psyBNC-2.4BETA2
PKGNAME=	psybnc-2.4b2
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=psybnc/}

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	http://www.psybnc.at/
COMMENT=	Easy-to-use, multi-user, IRC-Bouncer with many features
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/psybnc

USE_TOOLS+=	gmake

PSYBNC_USER?=		psybnc
PSYBNC_GROUP?=		psybnc
PKG_GROUPS=		${PSYBNC_USER}
PKG_USERS=		${PSYBNC_USER}:${PSYBNC_GROUP}
PKG_GROUPS_VARS+=	PSYBNC_GROUP
PKG_USERS_VARS+=	PSYBNC_USER

CONF_FILES=	share/examples/psybnc/psybnc.conf \
		${PKG_SYSCONFDIR}/psybnc.conf

SUBST_CLASSES+=		prefix
SUBST_FILES.prefix=	tools/autoconf.c
SUBST_SED.prefix=	-e "s|@PREFIX@|${PREFIX}|g"
SUBST_STAGE.prefix=	post-patch

SUBST_CLASSES+=         openssl
SUBST_FILES.openssl=	makefile.out
SUBST_SED.openssl=	-e "s|/usr/bin/openssl|openssl|g"
SUBST_SED.openssl=	-e "s|req -new|req -new -batch|g"
SUBST_STAGE.openssl=	post-configure

INSTALLATION_DIRS=	bin share/examples/psybnc
INSTALLATION_DIRS+=	share/doc/psybnc

do-configure:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
	${GMAKE}
	${CP} ${FILESDIR}/config.h ${WRKSRC}

do-build:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
	${GMAKE} -f makefile.out

do-install:
	${INSTALL_DATA}	${WRKSRC}/psybnc \
			${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/psybncchk \
			${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA}	${WRKSRC}/FAQ \
			${DESTDIR}${PREFIX}/share/doc/psybnc
	${INSTALL_DATA}	${WRKSRC}/README \
			${DESTDIR}${PREFIX}/share/doc/psybnc
	${INSTALL_DATA}	${WRKSRC}/scripts/SCRIPTING \
			${DESTDIR}${PREFIX}/share/doc/psybnc
	${INSTALL_DATA} ${WRKSRC}/scripts/example/DEFAULT.SCRIPT \
			${DESTDIR}${PREFIX}/share/examples/psybnc
	${INSTALL_DATA} ${WRKSRC}/psybnc.conf \
			${DESTDIR}${PREFIX}/share/examples/psybnc

.include "../../net/libcares/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
