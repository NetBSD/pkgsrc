# $NetBSD: buildlink3.mk,v 1.1 2004/02/11 01:04:37 xtraeme Exp $
#
# This Makefile fragment is included by packages that use libgnome.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBGNOME_BUILDLINK3_MK:=	${LIBGNOME_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libgnome
.endif

.if !empty(LIBGNOME_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			libgnome
BUILDLINK_DEPENDS.libgnome+=		libgnome>=2.4.0
BUILDLINK_PKGSRCDIR.libgnome?=		../../devel/libgnome

.include "../../audio/esound/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../sysutils/gnome-vfs2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"

.endif # LIBGNOME_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
