# $NetBSD: buildlink3.mk,v 1.1 2004/02/11 05:28:58 xtraeme Exp $
#
# This Makefile fragment is included by packages that use libgnomedb.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBGNOMEDB_BUILDLINK3_MK:=	${LIBGNOMEDB_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libgnomedb
.endif

.if !empty(LIBGNOMEDB_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			libgnomedb
BUILDLINK_DEPENDS.libgnomedb+=		libgnomedb>=1.0.0nb5
BUILDLINK_PKGSRCDIR.libgnomedb?=	../../databases/libgnomedb

.include "../../databases/libgda/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libbonoboui/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.endif # LIBGNOMEDB_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
