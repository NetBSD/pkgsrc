# $NetBSD: Makefile,v 1.1.1.1 2005/04/02 11:23:30 jdolecek Exp $

DISTNAME=	qca-1.0
PKGREVISION=	# empty
CATEGORIES=	security
MASTER_SITES=	http://delta.affinix.com/qca/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jdolecek@NetBSD.org
HOMEPAGE=	http://delta.affinix.com/qca/
COMMENT=	Cross-platform crypto API for QT

USE_BUILDLINK3=	yes
USE_GNU_TOOLS+= make
USE_LIBTOOL=	yes
USE_X11=	yes
HAS_CONFIGURE=	yes

do-install:
	cd ${WRKSRC} && ${INSTALL} src/qca.h ${PREFIX}/include
	cd ${WRKSRC} && \
	libtool --mode=install ${INSTALL_LIB} libqca.la ${PREFIX}/lib

.include "../../x11/qt3-libs/buildlink3.mk"
BUILDLINK_DEPMETHOD.qt3-tools= build
.include "../../x11/qt3-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
