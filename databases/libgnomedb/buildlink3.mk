# $NetBSD: buildlink3.mk,v 1.23 2008/01/18 05:06:27 tnn Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBGNOMEDB_BUILDLINK3_MK:=	${LIBGNOMEDB_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libgnomedb
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibgnomedb}
BUILDLINK_PACKAGES+=	libgnomedb
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libgnomedb

.if !empty(LIBGNOMEDB_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.libgnomedb+=	libgnomedb>=2.99.2
BUILDLINK_ABI_DEPENDS.libgnomedb+=	libgnomedb>=3.0.0nb2
BUILDLINK_PKGSRCDIR.libgnomedb?=	../../databases/libgnomedb
.endif	# LIBGNOMEDB_BUILDLINK3_MK

.include "../../databases/libgda/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../graphics/libgnomecanvas/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/gtksourceview/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
