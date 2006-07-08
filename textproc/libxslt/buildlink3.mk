# $NetBSD: buildlink3.mk,v 1.15 2006/07/08 23:11:11 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBXSLT_BUILDLINK3_MK:=	${LIBXSLT_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libxslt
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibxslt}
BUILDLINK_PACKAGES+=	libxslt
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libxslt

.if !empty(LIBXSLT_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.libxslt+=	libxslt>=1.1.8
BUILDLINK_ABI_DEPENDS.libxslt+=	libxslt>=1.1.15nb1
BUILDLINK_PKGSRCDIR.libxslt?=	../../textproc/libxslt
.endif	# LIBXSLT_BUILDLINK3_MK

.include "../../security/libgcrypt/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
