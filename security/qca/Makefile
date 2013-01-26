# $NetBSD: Makefile,v 1.25 2013/01/26 21:36:46 adam Exp $

DISTNAME=	qca-1.0
PKGREVISION=	9
CATEGORIES=	security
MASTER_SITES=	http://delta.affinix.com/download/qca/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://delta.affinix.com/qca/
COMMENT=	Cross-platform crypto API for QT

USE_TOOLS+= gmake
USE_LIBTOOL=	yes
HAS_CONFIGURE=	yes
USE_LANGUAGES=	c++

INSTALLATION_DIRS=	include lib
INSTALL_MAKE_FLAGS+=	INSTALL_ROOT=${DESTDIR}

.include "../../x11/qt3-libs/buildlink3.mk"
BUILDLINK_API_DEPENDS.qt3-tools+=	qt3-tools>=3.3.5nb6
.include "../../x11/qt3-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
