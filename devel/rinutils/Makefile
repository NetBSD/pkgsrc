# $NetBSD: Makefile,v 1.3 2022/06/28 11:33:42 wiz Exp $

DISTNAME=	rinutils-0.8.0
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=shlomif/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.shlomifish.org/open-source/projects/
COMMENT=	C11 / gnu11 utilities C library
LICENSE=	mit

USE_TOOLS+=	perl pkg-config
USE_CMAKE=	yes
USE_LANGUAGES=	c c++

.include "../../mk/bsd.pkg.mk"
