# $NetBSD: Makefile,v 1.7 2009/05/19 08:59:32 wiz Exp $

DISTNAME=	qca-2.0.2
PKGNAME=	qca2-${DISTNAME:C/.*-//}
CATEGORIES=	security
MASTER_SITES=	http://delta.affinix.com/download/qca/2.0/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jdolecek@NetBSD.org
HOMEPAGE=	http://delta.affinix.com/qca/
COMMENT=	Cross-platform crypto API for QT
LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=	gmake
USE_LIBTOOL=	yes
HAS_CONFIGURE=	yes
USE_LANGUAGES=	c++

INSTALLATION_DIRS=	qt4/include qt4/lib qt4/plugins/crypto

# install under qt4 prefix to not clash with qca 1.x
CONFIGURE_ARGS+=	--prefix=${QTDIR}
CONFIGURE_ARGS+=	--qtdir=${QTDIR}
CONFIGURE_ARGS+=	--disable-tests

post-install:
	${INSTALL_DATA} ${QTDIR}/lib/pkgconfig/qca2.pc ${DESTDIR}${PREFIX}/lib/pkgconfig/qca2.pc

.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
