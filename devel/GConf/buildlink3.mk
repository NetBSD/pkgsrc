# $NetBSD: buildlink3.mk,v 1.1 2004/02/26 17:29:24 jmmv Exp $
#
# This Makefile fragment is included by packages that use GConf.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GCONF_BUILDLINK3_MK:=	${GCONF_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	GConf
.endif

.if !empty(GCONF_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			GConf
BUILDLINK_DEPENDS.GConf+=		GConf>=1.0.9nb5
BUILDLINK_PKGSRCDIR.GConf?=		../../devel/GConf

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../databases/db3/buildlink3.mk"
.include "../../devel/oaf/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"

.endif # GCONF_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
