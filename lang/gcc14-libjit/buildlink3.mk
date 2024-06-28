# $NetBSD: buildlink3.mk,v 1.1 2024/06/28 18:35:17 wiz Exp $

BUILDLINK_TREE+=	gcc14-libjit

.if !defined(GCC14_LIBJIT_BUILDLINK3_MK)
GCC14_LIBJIT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gcc14-libjit+=	gcc14-libjit>=14.1.0
BUILDLINK_PKGSRCDIR.gcc14-libjit?=	../../lang/gcc14-libjit

BUILDLINK_PASSTHRU_DIRS+=			${BUILDLINK_PREFIX.gcc14-libjit}/gcc14
BUILDLINK_FNAME_TRANSFORM.gcc14-libjit+=	-e s,gcc14/lib,lib,
BUILDLINK_FNAME_TRANSFORM.gcc14-libjit+=	-e s,gcc14/include,include,
.endif	# GCC14_LIBJIT_BUILDLINK3_MK

BUILDLINK_TREE+=	-gcc14-libjit
