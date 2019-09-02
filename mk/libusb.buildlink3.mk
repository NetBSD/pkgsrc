# $NetBSD: libusb.buildlink3.mk,v 1.2 2019/09/02 02:23:02 rillig Exp $
#
# This Makefile is meant to be included by packages that require an
# implementation of the former libusb (still found in devel/libusb). The
# original implementation can be chosen by setting LIBUSB_TYPE to "native".
#
# The alternative implementation libusb-compat (found in devel/libusb-compat)
# wraps libusb1 (in devel/libusb1). This implementation can be chosen by setting
# LIBUSB_TYPE to "compat". On NetBSD, it has the advantage of not requiring root
# privileges to locate and use USB devices without a kernel driver.
#
# User-settable variables:
#
# LIBUSB_TYPE
#	The name of the libusb implementation to default to, native or compat.
#

MK_LIBUSB_BUILDLINK3_MK:=    ${MK_LIBUSB_BUILDLINK3_MK}+

.include "../../mk/bsd.fast.prefs.mk"

.if !empty(MK_LIBUSB_BUILDLINK3_MK:M+)

LIBUSB_TYPE?=	none

BUILD_DEFS+=	LIBUSB_TYPE

.  if ${LIBUSB_TYPE} == "native"
.    include "../../devel/libusb/buildlink3.mk"
.  elif ${LIBUSB_TYPE} == "compat"
.    include "../../devel/libusb-compat/buildlink3.mk"
.  else
PKG_FAIL_REASON+=	"[libusb.buildlink3.mk] Invalid value ${LIBUSB_TYPE} for LIBUSB_TYPE."
.  endif

.endif	# MK_LIBUSB_BUILDLINK3_MK
