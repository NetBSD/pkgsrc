# $NetBSD: buildlink3.mk,v 1.1 2004/02/10 02:16:02 xtraeme Exp $
#
# This Makefile fragment is included by packages that use libIDL.
#
# This file was created automatically using createbuildlink-3.0.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBIDL_BUILDLINK3_MK:=	${LIBIDL_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libIDL
.endif

.if !empty(LIBIDL_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			libIDL
BUILDLINK_DEPENDS.libIDL?=		libIDL>=0.8.3
BUILDLINK_PKGSRCDIR.libIDL?=		../../net/libIDL

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"

.endif # LIBIDL_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
