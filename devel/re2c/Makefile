# $NetBSD: Makefile,v 1.31 2024/12/30 18:49:09 wiz Exp $

DISTNAME=	re2c-4.0.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=skvadrik/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://re2c.org/
COMMENT=	Deterministic Finite State Automaton generator
LICENSE=	public-domain

USE_LANGUAGES=		c c++
USE_TOOLS+=		bison gmake
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-java
# needs 'make install'
TEST_TARGET=		check
PYTHON_FOR_BUILD_ONLY=	tool

.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
