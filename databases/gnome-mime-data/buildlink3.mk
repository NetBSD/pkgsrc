# $NetBSD: buildlink3.mk,v 1.2 2004/03/05 19:25:09 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
GNOME_MIME_DATA_BUILDLINK3_MK:=	${GNOME_MIME_DATA_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gnome-mime-data
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngnome-mime-data}
BUILDLINK_PACKAGES+=	gnome-mime-data

.if !empty(GNOME_MIME_DATA_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.gnome-mime-data+=	gnome-mime-data>=2.4.0
BUILDLINK_PKGSRCDIR.gnome-mime-data?=	../../databases/gnome-mime-data

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../lang/perl5/buildlink3.mk"

.endif	# GNOME_MIME_DATA_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
