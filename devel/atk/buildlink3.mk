# $NetBSD: buildlink3.mk,v 1.1 2004/02/10 01:56:42 xtraeme Exp $
#
# This Makefile fragment is included by packages that use atk.
#
# This file was created automatically using createbuildlink-3.0.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
ATK_BUILDLINK3_MK:=	${ATK_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	atk
.endif

.if !empty(ATK_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			atk
BUILDLINK_DEPENDS.atk?=		atk>=1.4.1
BUILDLINK_PKGSRCDIR.atk?=		../../devel/atk

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"

.endif # ATK_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
