# $NetBSD: Makefile,v 1.5 2005/06/17 03:50:32 jlam Exp $

DISTNAME=	qca-1.0
PKGREVISION=	# empty
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
BUILDLINK_DEPMETHOD.qt3-tools= build
.include "../../x11/qt3-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
