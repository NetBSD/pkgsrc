# $NetBSD: Makefile,v 1.2 2026/08/18 07:19:19 wiz Exp $

DISTNAME=		vali-0.1.1
CATEGORIES=		devel
MASTER_SITE_GITLAB=	https://gitlab.freedesktop.org/
MASTER_SITES=		${MASTER_SITE_GITLAB:=emersion/}
GITLAB_TAG=		v${PKGVERSION_NOREV}

MAINTAINER=		kikadf.01@gmail.com
HOMEPAGE=		https://gitlab.freedesktop.org/emersion/vali
COMMENT=		C library and code generator for Varlink
LICENSE=		mit

USE_TOOLS+=		pkg-config
WRKSRC=			${WRKDIR}/vali-${GITLAB_TAG}

PKGCONFIG_OVERRIDE_STAGE=	pre-build
PKGCONFIG_OVERRIDE=		output/meson-private/vali.pc

BUILDLINK_TRANSFORM+=	rm:-Wl,--fatal-warnings

.include "../../devel/meson/build.mk"
.include "../../textproc/json-c/buildlink3.mk"
.include "../../devel/aml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
