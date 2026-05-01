# $NetBSD: udev.buildlink3.mk,v 1.2 2026/05/01 20:06:30 vins Exp $
#
# This Makefile fragment is meant to be included in packages that
# require an implementation of the udev user-space library for querying
# information about devices.
#
# The variable UDEV_TYPE regulates the implementation to use.
#
# User-settable variables:
#
# UDEV_TYPE
#	The name of the libudev implementation to default to, either 
#	'eudev' or 'bsd'.
#
#	* 'eudev' uses the portable standalone version of the eudev library.
#	* 'bsd' uses libudev-bsd, an eudev port to BSD systems.
#
#	If unset, UDEV_TYPE will default to 'eudev' on Linux and to 'bsd' on *BSD.
#
# UDEV_REQUIRED
#
#	* 'yes' in any package which mandatory ask for a working udev API.
#	* 'no' in any package which udev support is optional for and can be
#	   successfully built without. This should be the preferred behavior
#	   under most circumstances.
#   
#	If unset, UDEV_REQUIRED defaults to 'no'. 
#

MK_UDEV_BUILDLINK3_MK:=    ${MK_UDEV_BUILDLINK3_MK}+

.include "../../mk/bsd.fast.prefs.mk"

.if !empty(MK_UDEV_BUILDLINK3_MK:M+)

.  if ${OPSYS:M*BSD}
UDEV_TYPE?=	bsd
.  elif ${OPSYS} == "Linux"
UDEV_TYPE?=	eudev
.else
UDEV_TYPE?=	none
.  endif

UDEV_REQUIRED?= no

BUILD_DEFS+=    UDEV_TYPE UDEV_REQUIRED

.  if ${UDEV_TYPE} == "eudev"
.    include "../../sysutils/libudev/buildlink3.mk"
.  elif ${UDEV_TYPE} == "bsd"
.    include "../../devel/libudev-bsd/buildlink3.mk"
.  elif ${UDEV_TYPE} == "none" && !empty(UDEV_REQUIRED:M[yY][eE][sS])
PKG_SKIP_REASON+= "${PKGNAME} requires a working udev API"
.  else 
.    if ${UDEV_TYPE} != "none"
PKG_FAIL_REASON+=	"[udev.buildlink3.mk] Invalid value ${UDEV_TYPE} for UDEV_TYPE."
.    endif
.  endif

.endif	# MK_UDEV_BUILDLINK3_MK
