# $NetBSD: buildlink3.mk,v 1.1 2004/02/11 00:48:07 xtraeme Exp $
#
# This Makefile fragment is included by packages that use gnome-mime-data.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GNOME_MIME_DATA_BUILDLINK3_MK:=	${GNOME_MIME_DATA_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gnome-mime-data
.endif

.if !empty(GNOME_MIME_DATA_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			gnome-mime-data
BUILDLINK_DEPENDS.gnome-mime-data+=	gnome-mime-data>=2.4.0
BUILDLINK_PKGSRCDIR.gnome-mime-data?=	../../databases/gnome-mime-data

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../lang/perl5/buildlink3.mk"

.endif # GNOME_MIME_DATA_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
