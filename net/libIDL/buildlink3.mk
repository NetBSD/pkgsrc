# $NetBSD: buildlink3.mk,v 1.4 2004/03/05 19:25:38 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBIDL_BUILDLINK3_MK:=	${LIBIDL_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libIDL
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:NlibIDL}
BUILDLINK_PACKAGES+=	libIDL

.if !empty(LIBIDL_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.libIDL+=	libIDL>=0.8.2
BUILDLINK_PKGSRCDIR.libIDL?=	../../net/libIDL

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"

.endif	# LIBIDL_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
