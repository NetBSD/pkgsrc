# $NetBSD: buildlink3.mk,v 1.6 2004/04/01 18:15:59 jmmv Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBIDL_BUILDLINK3_MK:=	${LIBIDL_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libIDL
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:NlibIDL}
BUILDLINK_PACKAGES+=	libIDL

.if !empty(LIBIDL_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.libIDL+=	libIDL>=0.8.3nb1
BUILDLINK_PKGSRCDIR.libIDL?=	../../net/libIDL
.endif	# LIBIDL_BUILDLINK3_MK

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
