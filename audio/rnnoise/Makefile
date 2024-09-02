# $NetBSD: Makefile,v 1.1 2024/09/02 16:04:24 nia Exp $

PKGNAME=	rnnoise-0.2
CATEGORIES=	audio
DIST_SUBDIR=	${PKGNAME_NOREV}
DISTFILES=	rnnoise.tar.gz
DISTFILES+=	rnnoise_data-0b50c45.tar.gz
SITES.rnnoise.tar.gz= \
	-https://gitlab.xiph.org/xiph/rnnoise/-/archive/v${PKGVERSION_NOREV}/rnnoise-v${PKGVERSION_NOREV}.tar.gz
SITES.rnnoise_data-0b50c45.tar.gz= \
	https://media.xiph.org/rnnoise/models/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitlab.xiph.org/xiph/rnnoise
COMMENT=	Recurrent neural network for audio noise reduction
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/rnnoise-v${PKGVERSION_NOREV}

USE_TOOLS+=	autoconf automake autoreconf

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

CONFIGURE_ARGS+=	--disable-doc
CONFIGURE_ARGS+=	--disable-examples
CONFIGURE_ARGS+=	--disable-x86-rtcd

PKGCONFIG_OVERRIDE+=	rnnoise.pc.in

post-extract:
	${MV} ${WRKDIR}/models ${WRKSRC}/models
	${MV} ${WRKDIR}/src/* ${WRKSRC}/src/

pre-configure:
	cd ${WRKSRC} && autoreconf -fi

.include "../../mk/bsd.pkg.mk"
