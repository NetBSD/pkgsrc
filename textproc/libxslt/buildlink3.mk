# $NetBSD: buildlink3.mk,v 1.3 2004/03/05 19:25:40 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBXSLT_BUILDLINK3_MK:=	${LIBXSLT_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libxslt
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibxslt}
BUILDLINK_PACKAGES+=	libxslt

.if !empty(LIBXSLT_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.libxslt+=	libxslt>=1.1.0
BUILDLINK_PKGSRCDIR.libxslt?=	../../textproc/libxslt

.include "../../lang/perl5/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"

.endif	# LIBXSLT_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
