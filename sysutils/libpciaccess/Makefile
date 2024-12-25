# $NetBSD: Makefile,v 1.36 2024/12/25 08:25:35 wiz Exp $

DISTNAME=	libpciaccess-0.18.1
CATEGORIES=	sysutils x11
MASTER_SITES=	${MASTER_SITE_XORG:=lib/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://xorg.freedesktop.org/
COMMENT=	PCI access utility library from X.org
LICENSE=	mit AND x11

DEPENDS+=	pciids-[0-9]*:../../misc/pciids

MESON_ARGS+=	-Dpci-ids=${PREFIX}/share/pciids
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=		output/meson-private/pciaccess.pc
PKGCONFIG_OVERRIDE_STAGE=	post-configure

# ../src/common_init.c:73:3: error: "Unsupported OS"
NOT_FOR_PLATFORM+=	Darwin-*-*

.include "../../devel/meson/build.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
