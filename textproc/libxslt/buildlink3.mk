# $NetBSD: buildlink3.mk,v 1.4 2004/03/18 09:12:15 jlam Exp $

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
.endif	# LIBXSLT_BUILDLINK3_MK

.include "../../lang/perl5/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
