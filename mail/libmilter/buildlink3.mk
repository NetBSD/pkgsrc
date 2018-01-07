# $NetBSD: buildlink3.mk,v 1.9 2018/01/07 13:04:21 rillig Exp $

BUILDLINK_TREE+=	libmilter

.if !defined(LIBMILTER_BUILDLINK3_MK)
LIBMILTER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libmilter+=	libmilter>=8.14
BUILDLINK_PKGSRCDIR.libmilter?=		../../mail/libmilter
BUILDLINK_DEPMETHOD.libmilter?=		build

PTHREAD_OPTS+=		require

.include "../../mk/pthread.buildlink3.mk"
.endif # LIBMILTER_BUILDLINK3_MK

BUILDLINK_TREE+=	-libmilter
