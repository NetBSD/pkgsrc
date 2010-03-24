# $NetBSD: buildlink3.mk,v 1.15 2010/03/24 21:54:16 asau Exp $

BUILDLINK_TREE+=	librep

.if !defined(LIBREP_BUILDLINK3_MK)
LIBREP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.librep+=	librep>=0.90.0
BUILDLINK_ABI_DEPENDS.librep?=	librep>=0.90.0nb1
BUILDLINK_PKGSRCDIR.librep?=	../../lang/librep
MAKE_FLAGS+=			rep_LIBTOOL=${LIBTOOL:Q}

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.endif # LIBREP_BUILDLINK3_MK

BUILDLINK_TREE+=	-librep
