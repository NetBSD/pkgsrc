# $NetBSD: buildlink3.mk,v 1.4 2022/06/28 11:31:46 wiz Exp $

BUILDLINK_TREE+=	libatomic

.if !defined(LIBATOMIC_BUILDLINK3_MK)
LIBATOMIC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libatomic+=	libatomic>=10.0
BUILDLINK_ABI_DEPENDS.libatomic+=	libatomic>=12.1.0nb1
BUILDLINK_PKGSRCDIR.libatomic?=		../../devel/libatomic

BUILDLINK_LDADD.libatomic+=	-latomic
BUILDLINK_LDFLAGS.libatomic?=	${BUILDLINK_LDADD.libatomic}

.include "../../mk/pthread.buildlink3.mk"
.endif

BUILDLINK_TREE+=	-libatomic
