# $NetBSD: options.mk,v 1.3 2024/02/12 13:13:07 gdt Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.tiff
PKG_SUPPORTED_OPTIONS=	lzw tiff-unsupported
PKG_SUGGESTED_OPTIONS=	lzw

.include "../../mk/bsd.options.mk"

###
### LZW compression support
###
.if !empty(PKG_OPTIONS:Mlzw)
CONFIGURE_ARGS+=	--enable-lzw
.else
CONFIGURE_ARGS+=	--disable-lzw
.endif

###
### Unsupported tools
###

# Upstream has withdrawn many command-line tools.  Most have been
# removed from the distfile.  tiff2ps and tiff2pdf are present but are
# not built by default.  Upstream notes:
#
#   Starting with libtiff v4.6.0, the source code for most TIFF tools
#   (except tiffinfo, tiffdump, tiffcp and tiffset) was discontinued,
#   due to the lack of contributors able to address reported security
#   issues. tiff2ps and tiff2pdf source code has been moved in a
#   unsupported category, no longer built by default, but are still
#   part of the the source distribution.  Other retired utilities are
#   in a archive/ directory, only available in the libtiff git
#   repository. Issues related to unsupported and archived tools will
#   no longer be accepted in the libtiff bug tracker.
#
# Therefore, any depending package or workflow that uses tiff2ps or
# tiffp2df is now buggy and should be fixed.  This option exists to
# make it easier for people to accommodate those packages/workflows
# until the problems are resolved.  Currently, the only known such
# package is hylafax.
#
# This option is subject to removal if its presence causes any
# trouble.

PLIST_VARS+=    	unsupported

.if !empty(PKG_OPTIONS:Mtiff-unsupported)
CONFIGURE_ARGS+=	--enable-tools-unsupported
PLIST.unsupported=      yes

WARNINGS+=	"Unsupported tools built:  Additional vulnerabilities are likely."
WARNINGS+=	"Unsupported tools built:  Bugs may not be reported upstream."
.endif
