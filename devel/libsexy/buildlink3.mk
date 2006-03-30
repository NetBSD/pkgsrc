# $NetBSD: buildlink3.mk,v 1.1.1.1 2006/03/30 21:02:04 jmmv Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBSEXY_BUILDLINK3_MK:=	${LIBSEXY_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libsexy
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibsexy}
BUILDLINK_PACKAGES+=	libsexy

.if !empty(LIBSEXY_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.libsexy+=	libsexy>=0.1.8
BUILDLINK_PKGSRCDIR.libsexy?=	../../devel/libsexy
.endif	# LIBSEXY_BUILDLINK3_MK

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
