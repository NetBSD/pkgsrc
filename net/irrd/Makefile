# $NetBSD: Makefile,v 1.54 2018/08/22 09:45:53 wiz Exp $

DISTNAME=		irrd2.3.9
PKGNAME=		irrd-2.3.9
PKGREVISION=		7
CATEGORIES=		net
MASTER_SITES=		http://www.irrd.net/
EXTRACT_SUFX=		.tgz

MAINTAINER=		kim@tac.nyc.ny.us
HOMEPAGE=		http://www.irrd.net/
COMMENT=		Internet Routing Registry Daemon
LICENSE=		original-bsd

MAKE_JOBS_SAFE=		no

DEPENDS+=		gnupg-[0-9]*:../../security/gnupg

USE_TOOLS+=		automake autoconf flex perl:run yacc wget:run

WRKSRC=			${WRKDIR}/${DISTNAME}/src

BUILD_DEFS+=		VARBASE

PKG_SYSCONFSUBDIR=	irrd
EGDIR=			${PREFIX}/share/examples/irrd
DOCDIR=			${PREFIX}/share/doc/irrd
CONF_FILES+=		${EGDIR}/irrd.conf ${PKG_SYSCONFDIR}/irrd.conf

IRRD_USER=		irrd
IRRD_GROUP=		irrd

PKG_GROUPS=		${IRRD_USER}
PKG_USERS=		${IRRD_USER:Q}:${IRRD_GROUP:Q}
PKG_GECOS.${IRRD_USER}=	IRRd user
RCD_SCRIPTS+=		irrd

GNU_CONFIGURE=		yes

CONFIGURE_ENV+=		WGET_PATH=${TOOLS_PATH.wget}

.include "options.mk"

REPLACE_PERL+=		programs/irrdcacher/irrdcacher
REPLACE_PERL+=		programs/irrdcacher/ripe2rpsl

FILES_SUBST+=		VARBASE=${VARBASE:Q}
FILES_SUBST+=		DOCDIR=${DOCDIR:Q}
FILES_SUBST+=		IRRD_USER=${IRRD_USER:Q}
FILES_SUBST+=		IRRD_GROUP=${IRRD_GROUP:Q}

INSTALLATION_DIRS+=	${PKGMANDIR}/man8
INSTALLATION_DIRS+=	sbin
INSTALLATION_DIRS+=	${EGDIR}
INSTALLATION_DIRS+=	${DOCDIR}

OWN_DIRS_PERMS+=	${PKG_SYSCONFDIR}/pgp ${IRRD_USER} ${IRRD_GROUP} 750
OWN_DIRS_PERMS+=	${VARBASE}/irrd/db ${IRRD_USER} ${IRRD_GROUP} 755
OWN_DIRS_PERMS+=	${VARBASE}/irrd/log ${IRRD_USER} ${IRRD_GROUP} 755

pre-configure:
	cd ${WRKSRC} && ${RM} acconfig.h && autoreconf

SUBST_CLASSES+=		confpaths
SUBST_FILES.confpaths=	../samples/irrd.conf.sample
SUBST_SED.confpaths=	-e 's,/var/spool/irr_database,'${VARBASE}'/irrd/db,'
SUBST_SED.confpaths+=	-e 's,/var/log/irrd,'${VARBASE}'/irrd/log/irrd.log,'
SUBST_STAGE.confpaths=	pre-configure

post-install:
	${INSTALL_DATA} ${WRKSRC}/../samples/irrd.conf.sample ${DESTDIR}${EGDIR}/irrd.conf
	${INSTALL_DATA} ${WRKSRC}/../irrd-user.pdf ${DESTDIR}${DOCDIR}/irrd-user.pdf
	${INSTALL_DATA} ${WRKSRC}/../irrd-user.sgml ${DESTDIR}${DOCDIR}/irrd-user.sgml
	cd ${WRKSRC}/programs/IRRd && ${MAKE} DESTDIR=${DESTDIR} install-man
	cd ${WRKSRC}/programs/irrdcacher && \
	${INSTALL_SCRIPT} irrdcacher ${DESTDIR}${PREFIX}/sbin && \
	${INSTALL_SCRIPT} ripe2rpsl ${DESTDIR}${PREFIX}/sbin

.include "../../mk/bsd.pkg.mk"
