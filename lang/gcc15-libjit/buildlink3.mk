# $NetBSD: buildlink3.mk,v 1.1 2025/08/05 23:33:11 wiz Exp $

BUILDLINK_TREE+=	gcc15-libjit

.if !defined(GCC15_LIBJIT_BUILDLINK3_MK)
GCC15_LIBJIT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gcc15-libjit+=	gcc15-libjit>=15.1.0
BUILDLINK_PKGSRCDIR.gcc15-libjit?=	../../lang/gcc15-libjit

BUILDLINK_PASSTHRU_DIRS+=			${BUILDLINK_PREFIX.gcc15-libjit}/gcc15
BUILDLINK_FNAME_TRANSFORM.gcc15-libjit+=	-e s,gcc15/lib,lib,
BUILDLINK_FNAME_TRANSFORM.gcc15-libjit+=	-e s,gcc15/include,include,
.endif	# GCC15_LIBJIT_BUILDLINK3_MK

BUILDLINK_TREE+=	-gcc15-libjit
