# $NetBSD: buildlink3.mk,v 1.1 2004/02/11 05:28:58 xtraeme Exp $
#
# This Makefile fragment is included by packages that use libgda.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBGDA_BUILDLINK3_MK:=	${LIBGDA_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libgda
.endif

.if !empty(LIBGDA_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			libgda
BUILDLINK_DEPENDS.libgda+=		libgda>=0.99.0nb1
BUILDLINK_PKGSRCDIR.libgda?=		../../databases/libgda

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"

.endif # LIBGDA_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
