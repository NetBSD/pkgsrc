# $NetBSD: Makefile,v 1.3 2020/11/25 21:48:54 nia Exp $

DISTNAME=	codecrypt-1.8
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=exaexa/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	https://github.com/exaexa/codecrypt
COMMENT=	Post-quantum cryptographic software
LICENSE=	gnu-lgpl-v3

USE_TOOLS+=	autoconf automake autoreconf gmake pkg-config bash
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES+=	c c++

LDFLAGS.SunOS+=	-lsocket -lnsl

CRYPTOPPFLAGS=	CRYPTOPP_CFLAGS=-I${PREFIX}/include
CRYPTOPPFLAGS+=	CRYPTOPP_LIBS='-L${PREFIX}/lib -Wl,-R${PREFIX}/lib -lcryptopp'

CONFIGURE_ENV+=	${CRYPTOPPFLAGS}
MAKE_ENV+=	${CRYPTOPPFLAGS}

pre-configure:
	cd ${WRKSRC} && bash autogen.sh

.include "../../devel/gmp/buildlink3.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../security/crypto++/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
