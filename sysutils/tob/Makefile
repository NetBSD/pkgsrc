# $NetBSD: Makefile,v 1.13 2012/10/23 19:51:27 asau Exp $

DISTNAME=	tob-0.25
PKGREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	http://tinyplanet.ca/projects/tob/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://tinyplanet.ca/projects/tob/
COMMENT=	General driver for making and maintaining backups

EGDIR=		${PREFIX}/share/examples/tob
CONF_FILES=	${EGDIR}/tob.rc ${PKG_SYSCONFDIR}/tob/tob.rc
CONF_FILES+=	${EGDIR}/example.exclude ${PKG_SYSCONFDIR}/tob/volumes/example.exclude
CONF_FILES+=	${EGDIR}/example.startdir ${PKG_SYSCONFDIR}/tob/volumes/example.startdir

INSTALLATION_DIRS=	${PKGMANDIR}/man8 sbin ${EGDIR}

REPLACE_SH+=		tob
USE_TOOLS+=		sh:run

SUBST_CLASSES+=		confdir
SUBST_STAGE.confdir=	do-build
SUBST_MESSAGE.confdir=	Adjusting configuration directory
SUBST_FILES.confdir=	tob tob.rc
SUBST_SED.confdir=	-e 's|@PKG_SYSCONFDIR@|${PKG_SYSCONFDIR}|g'
SUBST_SED.confdir+=	-e 's|@VARBASE@|${VARBASE}|g'

BUILD_DEFS+=		VARBASE

OWN_DIRS+=	${VARBASE}/tob ${PKG_SYSCONFDIR}/tob/volumes

do-build:
	@${DO_NADA}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/tob ${DESTDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/tob.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/
	${INSTALL_DATA} ${WRKSRC}/tob.rc ${DESTDIR}${EGDIR}/tob.rc
	${INSTALL_DATA} ${WRKSRC}/example.exclude ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/example.startdir ${DESTDIR}${EGDIR}

.include "../../mk/bsd.pkg.mk"
