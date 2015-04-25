# $NetBSD: Makefile,v 1.31 2015/04/25 14:24:49 tnn Exp $

DISTNAME=	qca-1.0
PKGREVISION=	15
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
