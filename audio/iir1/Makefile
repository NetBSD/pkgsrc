# $NetBSD: Makefile,v 1.2 2025/12/14 08:41:33 vins Exp $

DISTNAME=	iir1-1.9.5
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=berndporr/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://berndporr.github.io/iir1/
COMMENT=	DSP IIR Realtime C++ filter library
LICENSE=	mit

USE_LANGUAGES=	c c++

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
