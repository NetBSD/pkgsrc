# $NetBSD: Makefile,v 1.7 2019/11/04 21:12:55 rillig Exp $
#

DISTNAME=	lynis-2.6.2
CATEGORIES=	security
MASTER_SITES=	https://cisofy.com/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://cisofy.com/solutions/
COMMENT=	Perform security health scans for Linux, macOS, and Unix
LICENSE=	gnu-gpl-v3

NO_BUILD=	yes
USE_TOOLS+=	pax rm

SUBST_CLASSES+=		libdir
SUBST_STAGE.libdir=	pre-install
SUBST_MESSAGE.libdir=	Fixing lib path
SUBST_FILES.libdir=	lynis
SUBST_VARS.libdir=	PREFIX

SUBST_CLASSES+=		vardir
SUBST_STAGE.vardir=	pre-install
SUBST_MESSAGE.vardir=	Fixing var path
SUBST_FILES.vardir=	lynis
SUBST_VARS.vardir=	VARBASE

SUBST_CLASSES+=		confdir
SUBST_STAGE.confdir=	pre-install
SUBST_MESSAGE.confdir=	Fixing conf path
SUBST_FILES.confdir=	include/functions
SUBST_SED.confdir=	-e "s,@CONFDIR@,${PKG_SYSCONFDIR},"

WRKSRC=			${WRKDIR}/lynis
INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man8
INSTALLATION_DIRS+=	share/examples/lynis
INSTALLATION_DIRS+=	lib/lynis/db lib/lynis/extras
INSTALLATION_DIRS+=	lib/lynis/include lib/lynis/plugins

EGDIR=		${PREFIX}/share/examples/${PKGBASE}

BUILD_DEFS+=	PKG_SYSCONFBASE
BUILD_DEFS+=	VARBASE
AUTO_MKDIRS=	yes

PKG_SYSCONFSUBDIR=	lynis
CONF_FILES+=		share/examples/lynis/default.prf \
			${PKG_SYSCONFDIR}/default.prf
CONF_FILES+=		share/examples/lynis/developer.prf \
			${PKG_SYSCONFDIR}/developer.prf

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/lynis			\
		${DESTDIR}${PREFIX}/bin/lynis
	${INSTALL_MAN} ${WRKSRC}/lynis.8			\
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/lynis.8
	${INSTALL_DATA} ${WRKSRC}/default.prf			\
		${DESTDIR}${EGDIR}/default.prf
	${INSTALL_DATA} ${WRKSRC}/developer.prf			\
		${DESTDIR}${EGDIR}/developer.prf
	cd ${WRKSRC}/db && 					\
		${PAX} -wr * ${DESTDIR}${PREFIX}/lib/lynis/db
	cd ${WRKSRC}/extras && 					\
		${PAX} -wr * ${DESTDIR}${PREFIX}/lib/lynis/extras
	cd ${WRKSRC}/include && 				\
		${RM} *.orig
	cd ${WRKSRC}/include && 				\
		${PAX} -wr * ${DESTDIR}${PREFIX}/lib/lynis/include
	cd ${WRKSRC}/plugins && 				\
		${PAX} -wr * ${DESTDIR}${PREFIX}/lib/lynis/plugins

.include "../../mk/bsd.pkg.mk"
