# $NetBSD: buildlink3.mk,v 1.8 2010/06/02 12:50:03 adam Exp $

BUILDLINK_TREE+=	perdition

.if !defined(PERDITION_BUILDLINK3_MK)
PERDITION_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.perdition+=	perdition>=1.17
BUILDLINK_ABI_DEPENDS.perdition+=	perdition>=1.17nb1
BUILDLINK_PKGSRCDIR.perdition?=	../../mail/perdition

# The following are included in Makefile.common for "configure"'s sake.
#.include "../../devel/popt/buildlink3.mk"
.include "../../devel/vanessa_adt/buildlink3.mk"
.include "../../devel/vanessa_logger/buildlink3.mk"
#.include "../../devel/vanessa_socket/buildlink3.mk"
.endif # PERDITION_BUILDLINK3_MK

BUILDLINK_TREE+=	-perdition
