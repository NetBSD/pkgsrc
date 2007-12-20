# $NetBSD: Makefile,v 1.1.1.1 2007/12/20 20:17:47 jdolecek Exp $

DISTNAME=	qca-2.0.0
CATEGORIES=	security
MASTER_SITES=	http://delta.affinix.com/download/qca/2.0/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jdolecek@NetBSD.org
HOMEPAGE=	http://delta.affinix.com/qca/
COMMENT=	Cross-platform crypto API for QT

USE_TOOLS+= gmake
USE_LIBTOOL=	yes
HAS_CONFIGURE=	yes
USE_LANGUAGES=	c++

INSTALLATION_DIRS=	include lib

.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
