# $NetBSD: Makefile,v 1.16 2022/07/25 11:12:28 wiz Exp $

DISTNAME=	spice-protocol-0.14.3
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://spice-space.org/download/releases/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://spice-space.org/
COMMENT=	Headers defining protocols for SPICE server code
LICENSE=	modified-bsd AND mit

USE_LANGUAGES=	# none

PKGCONFIG_OVERRIDE_STAGE=	pre-install
PKGCONFIG_OVERRIDE+=		output/meson-private/spice-protocol.pc

PYTHON_FOR_BUILD_ONLY=	tool

.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
