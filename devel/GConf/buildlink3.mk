# $NetBSD: buildlink3.mk,v 1.10 2006/05/31 13:31:34 rillig Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GCONF_BUILDLINK3_MK:=	${GCONF_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	GConf
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:NGConf}
BUILDLINK_PACKAGES+=	GConf

.if !empty(GCONF_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.GConf+=	GConf>=1.0.9nb7
BUILDLINK_ABI_DEPENDS.GConf+=	GConf>=1.0.9nb10
BUILDLINK_PKGSRCDIR.GConf?=	../../devel/GConf
.endif	# GCONF_BUILDLINK3_MK

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/oaf/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
