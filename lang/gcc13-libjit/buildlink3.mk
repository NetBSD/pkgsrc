# $NetBSD: buildlink3.mk,v 1.1 2023/05/03 20:04:10 wiz Exp $

BUILDLINK_TREE+=	gcc13-libjit

.if !defined(GCC13_LIBJIT_BUILDLINK3_MK)
GCC13_LIBJIT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gcc13-libjit+=	gcc13-libjit>=13.1.0
BUILDLINK_PKGSRCDIR.gcc13-libjit?=	../../lang/gcc13-libjit

BUILDLINK_PASSTHRU_DIRS+=			${BUILDLINK_PREFIX.gcc13-libjit}/gcc13
BUILDLINK_FNAME_TRANSFORM.gcc13-libjit+=	-e s,gcc13/lib,lib,
BUILDLINK_FNAME_TRANSFORM.gcc13-libjit+=	-e s,gcc13/include,include,
.endif	# GCC13_LIBJIT_BUILDLINK3_MK

BUILDLINK_TREE+=	-gcc13-libjit
