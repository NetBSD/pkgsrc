# $NetBSD: Makefile,v 1.3 2005/02/20 00:52:46 xtraeme Exp $
#

DISTNAME=	libdfui-3.0
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.bsdinstaller.org/distfiles/

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://www.bsdinstaller.org/
COMMENT=	LIBrary for DragonFly User Interfaces

WRKSRC=		${WRKDIR}/libdfui
USE_BUILDLINK3=	yes

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	post-patch
SUBST_FILES.prefix=	Makefile
SUBST_SED.prefix=	-e "s,/usr/local,${PREFIX},g"
SUBST_MESSAGE.prefix=	"Fixing hardcoded paths."

INSTALLATION_DIRS=	include/dfui lib

HEADER_FILES=		dfui dump lang system

do-install:
.for f in ${HEADER_FILES}
	${INSTALL_DATA} ${WRKSRC}/${f}.h ${PREFIX}/include/dfui
.endfor
	${INSTALL_LIB} ${WRKSRC}/libdfui.so* ${PREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/libdfui*.a ${PREFIX}/lib

.include "../../devel/libaura/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
