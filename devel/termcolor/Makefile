# $NetBSD: Makefile,v 1.2 2025/08/20 11:34:53 wiz Exp $
#

DISTNAME=	termcolor-2.0.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=ikalnytskyi/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://termcolor.readthedocs.io/
COMMENT=	C++ library for printing colored messages to the terminal
LICENSE=	modified-bsd

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_POLICY_VERSION_MINIMUM=3.5

.include "../../mk/bsd.pkg.mk"
