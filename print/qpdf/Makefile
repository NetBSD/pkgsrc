# $NetBSD: Makefile,v 1.60 2024/03/11 15:11:59 ryoon Exp $

DISTNAME=	qpdf-11.9.0
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=qpdf/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://qpdf.sourceforge.io/
COMMENT=	Structural, content-preserving transformations on PDF files
LICENSE=	apache-2.0

CMAKE_CONFIGURE_ARGS+=	-DUSE_IMPLICIT_CRYPTO=off -DREQUIRE_CRYPTO_OPENSSL=on

USE_LANGUAGES=		c c++
USE_CXX_FEATURES+=	c++17

USE_TOOLS+=		pkg-config
PKGCONFIG_OVERRIDE+=	libqpdf.pc.in

CMAKE_ARGS+=		-DUSE_IMPLICIT_CRYPTO=OFF
CMAKE_ARGS+=		-DREQUIRE_CRYPTO_GNUTLS=OFF
CMAKE_ARGS+=		-DREQUIRE_CRYPTO_OPENSSL=ON
CMAKE_ARGS+=		-DDEFAULT_CRYPTO=openssl

.include "../../devel/cmake/build.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/atomic64.mk"
.include "../../mk/bsd.pkg.mk"
