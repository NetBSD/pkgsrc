# $NetBSD: buildlink3.mk,v 1.1 2004/01/22 11:04:59 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
IMLIB_BUILDLINK3_MK:=	${IMLIB_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	imlib
.endif

.if !empty(IMLIB_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=		imlib
BUILDLINK_DEPENDS.imlib?=	imlib>=1.9.14nb5
BUILDLINK_PKGSRCDIR.imlib?=	../../graphics/imlib

.  include "../../devel/gettext-lib/buildlink3.mk"
.  include "../../graphics/jpeg/buildlink3.mk"
.  include "../../graphics/libungif/buildlink3.mk"
.  include "../../graphics/netpbm/buildlink3.mk"
.  include "../../graphics/png/buildlink3.mk"
.  include "../../graphics/tiff/buildlink3.mk"
.  include "../../x11/gtk/buildlink3.mk"
.endif # IMLIB_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
