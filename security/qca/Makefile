# $NetBSD: Makefile,v 1.15 2007/12/20 20:37:21 jdolecek Exp $

DISTNAME=	qca-1.0
PKGREVISION=	3
CATEGORIES=	security
MASTER_SITES=	http://delta.affinix.com/qca/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jdolecek@NetBSD.org
HOMEPAGE=	http://delta.affinix.com/qca/
COMMENT=	Cross-platform crypto API for QT

USE_TOOLS+= gmake
USE_LIBTOOL=	yes
HAS_CONFIGURE=	yes
USE_LANGUAGES=	c++

INSTALLATION_DIRS=	include lib

.include "../../x11/qt3-libs/buildlink3.mk"
BUILDLINK_API_DEPENDS.qt3-tools+=	qt3-tools>=3.3.5nb6
.include "../../x11/qt3-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
