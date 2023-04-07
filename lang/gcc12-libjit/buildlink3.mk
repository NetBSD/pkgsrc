# $NetBSD: buildlink3.mk,v 1.1 2023/04/07 06:48:58 wiz Exp $

BUILDLINK_TREE+=	gcc12-libjit

.if !defined(GCC12_LIBJIT_BUILDLINK3_MK)
GCC12_LIBJIT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gcc12-libjit+=	gcc12-libjit>=12.2.0
BUILDLINK_PKGSRCDIR.gcc12-libjit?=	../../lang/gcc12-libjit

BUILDLINK_PASSTHRU_DIRS+=			${BUILDLINK_PREFIX.gcc12-libjit}/gcc12
BUILDLINK_FNAME_TRANSFORM.gcc12-libjit+=	-e s,gcc12/lib,lib,
BUILDLINK_FNAME_TRANSFORM.gcc12-libjit+=	-e s,gcc12/include,include,
.endif	# GCC12_LIBJIT_BUILDLINK3_MK

BUILDLINK_TREE+=	-gcc12-libjit
