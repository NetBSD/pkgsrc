# $NetBSD: buildlink3.mk,v 1.11 2006/07/08 23:10:39 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
GNOME_MIME_DATA_BUILDLINK3_MK:=	${GNOME_MIME_DATA_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gnome-mime-data
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngnome-mime-data}
BUILDLINK_PACKAGES+=	gnome-mime-data
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}gnome-mime-data

.if !empty(GNOME_MIME_DATA_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.gnome-mime-data+=	gnome-mime-data>=2.4.0
BUILDLINK_ABI_DEPENDS.gnome-mime-data+=	gnome-mime-data>=2.4.2nb2
BUILDLINK_PKGSRCDIR.gnome-mime-data?=	../../databases/gnome-mime-data

# intltool-{extract,merge,update} are Perl scripts included in the sources
# of packages that use gnome-mime-data and are executed during build.
#
USE_TOOLS+=	perl

.endif	# GNOME_MIME_DATA_BUILDLINK3_MK

.include "../../devel/gettext-lib/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
