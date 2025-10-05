# $NetBSD: Makefile,v 1.5 2025/10/05 19:25:39 js Exp $

DISTNAME=	boca-1.0.7
PKGREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=enzo1982/}
GITHUB_PROJECT=	BoCA
GITHUB_RELEASE=	v1.0.7

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/enzo1982/BoCA/
COMMENT=	Component library used by the fre:ac (audio/freac)
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake
CFLAGS+=	-I${BUILDLINK_DIR}/include

MAKE_FLAGS=	prefix=${PREFIX}

.include "../../devel/smooth/buildlink3.mk"
.include "../../misc/libcdio-paranoia/buildlink3.mk"
.include "../../textproc/uriparser/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
