# $NetBSD: Makefile,v 1.16 2023/11/07 21:35:09 wiz Exp $

DISTNAME=	TECkit-2.5.12
CATEGORIES=	converters
MASTER_SITES=	${MASTER_SITE_GITHUB:=silnrsi/}
GITHUB_PROJECT=	teckit
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/silnrsi/teckit/
COMMENT=	Low-level toolkit to perform encoding conversions
LICENSE=	gnu-lgpl-v2.1 OR cpl-1.0

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	aclocal autoconf automake gmake

USE_CXX_FEATURES=	c++11

PKGCONFIG_OVERRIDE=	teckit.pc.in

pre-configure:
	cd ${WRKSRC} && libtoolize -c && aclocal && \
	    autoheader && autoconf && automake -a

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
