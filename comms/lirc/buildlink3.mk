# $NetBSD: buildlink3.mk,v 1.2 2012/12/02 01:27:16 cheusov Exp $

# Check whether LIRC is available on this platform
.include "available.mk"
.if ${LIRC_AVAILABLE} == "yes"

BUILDLINK_TREE+=	lirc

.  if !defined(LIRC_BUILDLINK3_MK)
LIRC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.lirc+=	lirc>=0.9.0
BUILDLINK_PKGSRCDIR.lirc?=	../../comms/lirc
.  endif # LIRC_BUILDLINK3_MK

BUILDLINK_TREE+=	-lirc
.endif # LIRC_AVAILABLE
