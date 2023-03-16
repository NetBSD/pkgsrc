# $NetBSD: Makefile,v 1.5 2023/03/16 08:06:13 adam Exp $

DISTNAME=	rinutils-0.10.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=shlomif/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.shlomifish.org/open-source/projects/
COMMENT=	C11 / gnu11 utilities C library
LICENSE=	mit

USE_LANGUAGES=	c c++
USE_TOOLS+=	perl

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
