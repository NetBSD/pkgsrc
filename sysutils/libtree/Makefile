# $NetBSD: Makefile,v 1.6 2022/12/12 14:10:48 nros Exp $

DISTNAME=	libtree-3.1.1
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

.include "../../mk/bsd.pkg.mk"
