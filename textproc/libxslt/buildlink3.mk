# $NetBSD: buildlink3.mk,v 1.10 2005/07/16 19:10:40 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBXSLT_BUILDLINK3_MK:=	${LIBXSLT_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libxslt
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibxslt}
BUILDLINK_PACKAGES+=	libxslt

.if !empty(LIBXSLT_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.libxslt+=	libxslt>=1.1.8
BUILDLINK_RECOMMENDED.libxslt+=	libxslt>=1.1.10nb1
BUILDLINK_PKGSRCDIR.libxslt?=	../../textproc/libxslt
.endif	# LIBXSLT_BUILDLINK3_MK

.include "../../security/libgcrypt/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
