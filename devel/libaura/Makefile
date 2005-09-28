# $NetBSD: Makefile,v 1.5 2005/09/28 14:31:06 rillig Exp $
#

DISTNAME=	libaura-2.0
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.bsdinstaller.org/distfiles/

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://www.bsdinstaller.org/
COMMENT=	LIBrary of Assorted Useful Reusable Abstraction

WRKSRC=		${WRKDIR}/libaura

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	post-patch
SUBST_FILES.prefix=	Makefile
SUBST_SED.prefix=	-e "s,/usr/local,${PREFIX},g"
SUBST_MESSAGE.prefix=	"Fixing hardcoded paths."

INSTALLATION_DIRS=	include/aura lib

do-install:
	${INSTALL_DATA} ${WRKSRC}/*.h ${PREFIX}/include/aura
	${INSTALL_LIB} ${WRKSRC}/libaura.so* ${PREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/*.a ${PREFIX}/lib

.include "../../mk/bsd.pkg.mk"
