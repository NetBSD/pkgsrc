# $NetBSD: buildlink3.mk,v 1.1 2004/02/11 05:43:54 xtraeme Exp $
#
# This Makefile fragment is included by packages that use libgsf.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBGSF_BUILDLINK3_MK:=	${LIBGSF_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libgsf
.endif

.if !empty(LIBGSF_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			libgsf
BUILDLINK_DEPENDS.libgsf+=		libgsf>=1.8.2nb3
BUILDLINK_PKGSRCDIR.libgsf?=		../../devel/libgsf

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../sysutils/gnome-vfs2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"

.endif # LIBGSF_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
