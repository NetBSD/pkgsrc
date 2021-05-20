# $NetBSD: Makefile,v 1.1 2021/05/20 19:52:31 nia Exp $

DISTNAME=	cglm-0.8.2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=recp/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/recp/cglm
COMMENT=	OpenGL Mathematics for C
LICENSE=	mit

PKGCONFIG_OVERRIDE_STAGE=	pre-install
PKGCONFIG_OVERRIDE+=		output/meson-private/cglm.pc

.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
