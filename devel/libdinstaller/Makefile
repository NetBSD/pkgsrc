# $NetBSD: Makefile,v 1.1.1.1 2005/02/09 05:42:43 xtraeme Exp $
#

DISTNAME=	libinstaller-4.0
CATEGORIES=	devel
MASTER_SITES=	http://www.bsdinstaller.org/distfiles/

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://www.bsdinstaller.org/
COMMENT=	Library of support functions for the BSD Installer application

WRKSRC=		${WRKDIR}/libinstaller
USE_BUILDLINK3=	yes

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	post-patch
SUBST_FILES.prefix=	Makefile
SUBST_SED.prefix=	-e "s,/usr/local,${PREFIX},g"
SUBST_MESSAGE.prefix=	"Fixing hardcoded paths."

.include "../../devel/libaura/buildlink3.mk"
.include "../../devel/libdfui/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
