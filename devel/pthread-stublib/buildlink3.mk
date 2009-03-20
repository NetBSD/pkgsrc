# $NetBSD: buildlink3.mk,v 1.6 2009/03/20 19:24:27 joerg Exp $
# XXX
# XXX This file was created automatically using createbuildlink-3.10.
# XXX After this file has been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink3.mk files.
# XXX
# XXX Packages that only install static libraries or headers should
# XXX include the following line:
# XXX
# XXX	BUILDLINK_DEPMETHOD.pthread-stublib?=	build

BUILDLINK_TREE+=	pthread-stublib

.if !defined(PTHREAD_STUBLIB_BUILDLINK3_MK)
PTHREAD_STUBLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.pthread-stublib+=	pthread-stublib>=1.0
BUILDLINK_PKGSRCDIR.pthread-stublib?=	../../devel/pthread-stublib

IS_BUILTIN.pthread-stublib=no
.endif # PTHREAD_STUBLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-pthread-stublib
