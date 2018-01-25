# $NetBSD: Makefile,v 1.9 2018/01/25 15:51:24 jperkin Exp $

DISTNAME=	TECkit-2.5.7
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
USE_TOOLS+=	autoconf automake

PKGCONFIG_OVERRIDE=	teckit.pc.in

pre-configure:
	(cd ${WRKSRC}; ./autogen.sh)

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
