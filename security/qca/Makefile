# $NetBSD: Makefile,v 1.10 2006/03/13 21:56:22 minskim Exp $

DISTNAME=	qca-1.0
PKGREVISION=	2
CATEGORIES=	security
MASTER_SITES=	http://delta.affinix.com/qca/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jdolecek@NetBSD.org
HOMEPAGE=	http://delta.affinix.com/qca/
COMMENT=	Cross-platform crypto API for QT

USE_TOOLS+= gmake
USE_LIBTOOL=	yes
HAS_CONFIGURE=	yes

INSTALLATION_DIRS=	include lib

.include "../../x11/qt3-libs/buildlink3.mk"
BUILDLINK_DEPENDS.qt3-tools+=	qt3-tools>=3.3.5nb6
.include "../../x11/qt3-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
