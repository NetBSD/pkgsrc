# $NetBSD: buildlink3.mk,v 1.2 2004/02/10 20:45:02 jlam Exp $
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
BUILDLINK_DEPENDS.libIDL?=		libIDL>=0.8.2
BUILDLINK_PKGSRCDIR.libIDL?=		../../net/libIDL

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"

.endif # LIBIDL_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
