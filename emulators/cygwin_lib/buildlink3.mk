# $NetBSD: buildlink3.mk,v 1.7 2018/01/07 13:04:11 rillig Exp $

BUILDLINK_TREE+=	cygwin_lib

.if !defined(CYGWIN_LIB_BUILDLINK3_MK)
CYGWIN_LIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cygwin_lib+=	cygwin_lib>=1.5.11.1
BUILDLINK_PKGSRCDIR.cygwin_lib?=	../../emulators/cygwin_lib
.endif # CYGWIN_LIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-cygwin_lib
