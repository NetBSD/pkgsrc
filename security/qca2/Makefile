# $NetBSD: Makefile,v 1.5 2009/01/27 11:10:46 markd Exp $

DISTNAME=	qca-2.0.1
PKGNAME=	qca2-${DISTNAME:C/.*-//}
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

INSTALLATION_DIRS=	qt4/include qt4/lib qt4/plugins/crypto

# install under qt4 prefix to not clash with qca 1.x
CONFIGURE_ARGS+=	--prefix=${QTDIR}
CONFIGURE_ARGS+=	--qtdir=${QTDIR}
CONFIGURE_ARGS+=	--disable-tests

post-install:
	${CP} ${QTDIR}/lib/pkgconfig/qca2.pc ${PREFIX}/lib/pkgconfig/qca2.pc

.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
