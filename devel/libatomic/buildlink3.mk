# $NetBSD: buildlink3.mk,v 1.5 2024/03/10 10:18:21 he Exp $

BUILDLINK_TREE+=	libatomic

.if !defined(LIBATOMIC_BUILDLINK3_MK)
LIBATOMIC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libatomic+=	libatomic>=10.0
BUILDLINK_ABI_DEPENDS.libatomic+=	libatomic>=12.1.0nb1
BUILDLINK_PKGSRCDIR.libatomic?=		../../devel/libatomic

BUILDLINK_LDADD.libatomic+=	-latomic
BUILDLINK_LDFLAGS.libatomic?=	${BUILDLINK_LDADD.libatomic}

# Make this work for rust as well:
RUSTFLAGS+=	-C link-arg=${BUILDLINK_LDADD.libatomic}
RUSTFLAGS+=	-C link-arg=-L${BUILDLINK_PREFIX.libatomic}/lib
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX}/lib

.include "../../mk/pthread.buildlink3.mk"
.endif

BUILDLINK_TREE+=	-libatomic
