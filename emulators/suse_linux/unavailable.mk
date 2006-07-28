# $NetBSD: unavailable.mk,v 1.2 2006/07/28 22:57:38 kristerw Exp $

.ifndef SUSE_UNAVAILABLE_MK
SUSE_UNAVAILABLE_MK=1

# We put a value here so that the creation of the bulk build cache files
# works correctly on all machines.  This speeds up the marking of all
# COMPAT_LINUX packages as not available.
#
SUSE_DIR_PREFIX=	suse100
SUSE_VERSION=		0
PKG_SKIP_REASON+=	"${PKGNAME} is not available for ${MACHINE_PLATFORM}"

# By default, we can't check for missing shared libraries nor note which
# shared libraries are provided and/or required by the package since the
# library support is via syscall emulation.
#
CHECK_SHLIBS_SUPPORTED?=	no

.endif # SUSE_UNAVAILABLE_MK
