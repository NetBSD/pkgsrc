# $NetBSD: buildlink3.mk,v 1.13 2009/03/20 19:24:50 joerg Exp $

BUILDLINK_TREE+=	librep

.if !defined(LIBREP_BUILDLINK3_MK)
LIBREP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.librep+=	librep>=0.17
BUILDLINK_ABI_DEPENDS.librep+=	librep>=0.17nb2
BUILDLINK_PKGSRCDIR.librep?=	../../lang/librep
MAKE_FLAGS+=			rep_LIBTOOL=${LIBTOOL:Q}

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.endif # LIBREP_BUILDLINK3_MK

BUILDLINK_TREE+=	-librep
