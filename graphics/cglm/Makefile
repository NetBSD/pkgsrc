# $NetBSD: Makefile,v 1.2 2024/12/16 07:59:07 wiz Exp $

DISTNAME=	cglm-0.9.4
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
