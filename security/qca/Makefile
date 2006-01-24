# $NetBSD: Makefile,v 1.8 2006/01/24 07:32:33 wiz Exp $

DISTNAME=	qca-1.0
PKGREVISION=	1
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

do-install:
	cd ${WRKSRC} && ${INSTALL} src/qca.h ${PREFIX}/include
	cd ${WRKSRC} && \
	libtool --mode=install ${INSTALL_LIB} libqca.la ${PREFIX}/lib

.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../x11/qt3-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
