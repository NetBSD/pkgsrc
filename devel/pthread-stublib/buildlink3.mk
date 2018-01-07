# $NetBSD: buildlink3.mk,v 1.8 2018/01/07 13:04:10 rillig Exp $

BUILDLINK_TREE+=	pthread-stublib

.if !defined(PTHREAD_STUBLIB_BUILDLINK3_MK)
PTHREAD_STUBLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.pthread-stublib+=	pthread-stublib>=1.0
BUILDLINK_PKGSRCDIR.pthread-stublib?=	../../devel/pthread-stublib

IS_BUILTIN.pthread-stublib=	no
.endif # PTHREAD_STUBLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-pthread-stublib
