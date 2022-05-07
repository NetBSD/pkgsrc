# $NetBSD: Makefile,v 1.4 2022/05/07 17:52:26 wiz Exp $

DISTNAME=	libtree-3.1.0
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=haampie/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/haampie/libtree
COMMENT=	Show library info in a tree form
LICENSE=	mit

USE_LANGUAGES=	c99
USE_TOOLS+=	gmake

MAKE_FLAGS=	SHAREDIR=${PREFIX}

.include "../../devel/cxxopts/buildlink3.mk"
.include "../../devel/elfio/buildlink3.mk"
.include "../../devel/termcolor/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
