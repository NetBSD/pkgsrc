# $NetBSD: Makefile,v 1.55 2023/09/01 09:55:26 nia Exp $

DISTNAME=	qpdf-11.4.0
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=qpdf/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://qpdf.sourceforge.io/
COMMENT=	Structural, content-preserving transformations on PDF files
LICENSE=	apache-2.0

USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config
PKGCONFIG_OVERRIDE+=	libqpdf.pc.in

USE_CXX_FEATURES+=	c++17

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
