# $NetBSD: Makefile,v 1.42 2023/10/24 22:09:50 wiz Exp $
#

DISTNAME=		spamdyke-5.0.1
PKGREVISION=		5
CATEGORIES=		mail
MASTER_SITES=		${HOMEPAGE}releases/
EXTRACT_SUFX=		.tgz

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://www.spamdyke.org/
COMMENT=		Filters incoming SMTP connections to qmail
LICENSE=		gnu-gpl-v2

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}/${PKGBASE}

GNU_CONFIGURE=		yes
BUILD_TARGET=		${PKGBASE}
MAKE_FLAGS+=		CFLAGS=${CFLAGS:Q}
MAKE_FLAGS+=		LDFLAGS=${LDFLAGS:Q}

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	spamdyke.h
SUBST_VARS.paths=	PREFIX
SUBST_VARS.paths+=	QMAILDIR
SUBST_STAGE.paths=	do-configure

BUILD_DEFS+=		QMAILDIR

EGDIR=			${PREFIX}/share/examples/${PKGBASE}
CONF_FILES+=		${EGDIR}/spamdyke.conf.example ${PKG_SYSCONFDIR}/spamdyke.conf

INSTALLATION_DIRS=	bin share/doc/${PKGBASE} share/examples/${PKGBASE}

.include "options.mk"

do-install:
	cd ${WRKSRC};							\
	for f in spamdyke; do						\
		${INSTALL_PROGRAM} $${f} ${DESTDIR}${PREFIX}/bin;	\
	done;								\
	cd ../documentation;						\
	${INSTALL_DATA} spamdyke.conf.example ${DESTDIR}${EGDIR};	\
	for f in *.txt *.html; do					\
		${INSTALL_DATA} $${f} ${DESTDIR}${PREFIX}/share/doc/${PKGBASE};\
	done

.include "../../mk/resolv.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
