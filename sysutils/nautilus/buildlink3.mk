# $NetBSD: buildlink3.mk,v 1.1 2004/02/11 06:30:13 xtraeme Exp $
#
# This Makefile fragment is included by packages that use nautilus.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
NAUTILUS_BUILDLINK3_MK:=	${NAUTILUS_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	nautilus
.endif

.if !empty(NAUTILUS_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			nautilus
BUILDLINK_DEPENDS.nautilus+=		nautilus>=2.4.2
BUILDLINK_PKGSRCDIR.nautilus?=		../../sysutils/nautilus

.include "../../devel/libgsf/buildlink3.mk"
.include "../../devel/eel2/buildlink3.mk"
.include "../../graphics/imlib2/buildlink3.mk"
.include "../../graphics/librsvg2/buildlink3.mk"
.include "../../x11/gnome-desktop/buildlink3.mk"

.endif # NAUTILUS_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
