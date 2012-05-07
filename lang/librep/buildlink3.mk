# $NetBSD: buildlink3.mk,v 1.19 2012/05/07 01:53:41 dholland Exp $

BUILDLINK_TREE+=	librep

.if !defined(LIBREP_BUILDLINK3_MK)
LIBREP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.librep+=	librep>=0.91.0
BUILDLINK_ABI_DEPENDS.librep+=	librep>=0.91.0nb1
BUILDLINK_PKGSRCDIR.librep?=	../../lang/librep
MAKE_FLAGS+=			rep_LIBTOOL=${LIBTOOL:Q}

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/libffi/buildlink3.mk"
.endif # LIBREP_BUILDLINK3_MK

BUILDLINK_TREE+=	-librep
