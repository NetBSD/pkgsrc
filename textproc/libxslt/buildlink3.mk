# $NetBSD: buildlink3.mk,v 1.2 2004/02/10 20:45:02 jlam Exp $
#
# This Makefile fragment is included by packages that use libxslt.
#
# This file was created automatically using createbuildlink-3.0.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBXSLT_BUILDLINK3_MK:=	${LIBXSLT_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libxslt
.endif

.if !empty(LIBXSLT_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			libxslt
BUILDLINK_DEPENDS.libxslt+=		libxslt>=1.1.0
BUILDLINK_PKGSRCDIR.libxslt?=		../../textproc/libxslt

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../lang/perl5/buildlink3.mk"

.endif # LIBXSLT_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
