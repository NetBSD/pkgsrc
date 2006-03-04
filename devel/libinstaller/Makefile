# $NetBSD: Makefile,v 1.5 2006/03/04 21:29:17 jlam Exp $
#

DISTNAME=	libinstaller-4.0
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.bsdinstaller.org/distfiles/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.bsdinstaller.org/
COMMENT=	Library of support functions for the BSD Installer application

WRKSRC=		${WRKDIR}/libinstaller

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-patch
SUBST_FILES.prefix=	Makefile
SUBST_SED.prefix=	-e "s,/usr/local,${PREFIX},g"
SUBST_MESSAGE.prefix=	"Fixing hardcoded paths."

INSTALLATION_DIRS=	include/installer lib

HEADER_FILES=		commands confed diskutil functions package uiutil

do-install:
.for f in ${HEADER_FILES}
	${INSTALL_DATA} ${WRKSRC}/${f}.h ${PREFIX}/include/installer
.endfor
	${INSTALL_LIB} ${WRKSRC}/libinstaller.so* ${PREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/libinstaller*.a ${PREFIX}/lib

.include "../../devel/libaura/buildlink3.mk"
.include "../../devel/libdfui/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
