# $NetBSD: buildlink3.mk,v 1.1 2026/08/10 21:42:39 wiz Exp $

BUILDLINK_TREE+=	gcc16-libjit

.if !defined(GCC16_LIBJIT_BUILDLINK3_MK)
GCC16_LIBJIT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gcc16-libjit+=	gcc16-libjit>=16.1.0
BUILDLINK_PKGSRCDIR.gcc16-libjit?=	../../lang/gcc16-libjit

BUILDLINK_PASSTHRU_DIRS+=			${BUILDLINK_PREFIX.gcc16-libjit}/gcc16
BUILDLINK_FNAME_TRANSFORM.gcc16-libjit+=	-e s,gcc16/lib,lib,
BUILDLINK_FNAME_TRANSFORM.gcc16-libjit+=	-e s,gcc16/include,include,
.endif	# GCC16_LIBJIT_BUILDLINK3_MK

BUILDLINK_TREE+=	-gcc16-libjit
