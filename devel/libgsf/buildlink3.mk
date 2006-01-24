# $NetBSD: buildlink3.mk,v 1.9 2006/01/24 07:32:03 wiz Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBGSF_BUILDLINK3_MK:=	${LIBGSF_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libgsf
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibgsf}
BUILDLINK_PACKAGES+=	libgsf

.if !empty(LIBGSF_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.libgsf+=	libgsf>=1.13.3
BUILDLINK_RECOMMENDED.libgsf?=	libgsf>=1.13.3nb2
BUILDLINK_PKGSRCDIR.libgsf?=	../../devel/libgsf
.endif	# LIBGSF_BUILDLINK3_MK

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../sysutils/gnome-vfs2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
