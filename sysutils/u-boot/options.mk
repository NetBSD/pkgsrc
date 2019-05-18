# $NetBSD: options.mk,v 1.1 2019/05/18 18:01:34 thorpej Exp $

#
# u-boot meta-package options:
#
# amlogic-meson:
# Build u-boot for boards based on Amlogic Meson SoCs.  Disabled by
# default because these u-boot packages require amlogic-meson-fwtools
# to build.
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.u-boot
PKG_SUPPORTED_OPTIONS=	amlogic-meson
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"
