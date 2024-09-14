# $NetBSD: Makefile,v 1.15 2024/09/14 13:24:10 pin Exp $

DISTNAME=	rsftch-0.7.6
CATEGORIES=	sysutils
MASTER_SITES=	https://static.crates.io/crates/rsftch/
EXTRACT_SUFX=	.crate

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/charklie/rsftch/
COMMENT=	Lightning fast hardware fetch
LICENSE=	gnu-gpl-v3

.include "cargo-depends.mk"

#RUST_REQ=	1.80.1
#Upstream does not state the required MSRV.
#This package is confirmed to build with Rust 1.80.1 on amd64
USE_TOOLS+=	pkg-config

RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.libX11}/lib
RUSTFLAGS+=	-C link-arg=-L${BUILDLINK_PREFIX.libX11}/lib

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} != "NetBSD" || ${X11_TYPE} == "modular"
DEPENDS+=	xrandr-[0-9]*:../../x11/xrandr
.endif

CHECK_WRKREF_SKIP+=	bin/rsftch

.include "../../lang/rust/cargo.mk"
.if ${OPSYS} == "Linux"
.include "../../sysutils/pciutils/buildlink3.mk"
# On Linux, this package also uses lm_sensors at runtime.
# https://hwmon.wiki.kernel.org/lm_sensors
# https://github.com/lm-sensors/lm-sensors
# We currently, don't have this in pkgsrc.
# If, you are on Linux, install lm_sensors from your distro else,
# this will build but, panic at runtime.
.endif
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
