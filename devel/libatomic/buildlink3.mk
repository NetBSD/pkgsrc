# $NetBSD: buildlink3.mk,v 1.1 2020/06/02 21:26:03 maya Exp $

BUILDLINK_TREE+=	libatomic

.if !defined(LIBATOMIC_BUILDLINK3_MK)
LIBATOMIC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libatomic+=	libatomic>=10.0
BUILDLINK_ABI_DEPENDS.libatomic+=	libatomic>=10.0
BUILDLINK_PKGSRCDIR.libatomic?=		../../wip/libatomic

.include "../../mk/pthread.buildlink3.mk"
.endif

BUILDLINK_TREE+=	-libatomic
