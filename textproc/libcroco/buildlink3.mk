# $NetBSD: buildlink3.mk,v 1.1 2004/02/11 06:18:33 xtraeme Exp $
#
# This Makefile fragment is included by packages that use libcroco.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBCROCO_BUILDLINK3_MK:=	${LIBCROCO_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libcroco
.endif

.if !empty(LIBCROCO_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			libcroco
BUILDLINK_DEPENDS.libcroco+=		libcroco>=0.4.0
BUILDLINK_PKGSRCDIR.libcroco?=		../../textproc/libcroco

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"

.endif # LIBCROCO_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
