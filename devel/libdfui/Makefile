# $NetBSD: Makefile,v 1.2 2005/02/20 00:33:18 xtraeme Exp $
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

.include "../../devel/libaura/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
