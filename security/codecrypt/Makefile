# $NetBSD: Makefile,v 1.1 2016/04/30 19:27:43 agc Exp $

DISTNAME=	codecrypt-1.7.5
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=exaexa/}
GITHUB_TAG=	v1.7.5

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	https://github.com/exaexa/codecrypt
COMMENT=	Post-quantum cryptographic software
LICENSE=	gnu-lgpl-v3

USE_TOOLS+=	autoconf automake autoreconf gmake pkg-config
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES+=	c c++

CRYPTOPPFLAGS=	CRYPTOPP_CFLAGS=-I${PREFIX}/include
CRYPTOPPFLAGS+=	CRYPTOPP_LIBS='-L${PREFIX}/lib -Wl,-R${PREFIX}/lib -lcryptopp'

CONFIGURE_ENV+=	${CRYPTOPPFLAGS}
MAKE_ENV+=	${CRYPTOPPFLAGS}

pre-configure:
	cd ${WRKSRC} && ./autogen.sh

.include "../../devel/gmp/buildlink3.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../security/crypto++/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
