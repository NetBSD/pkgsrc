# $NetBSD: buildlink3.mk,v 1.2 2004/03/05 19:25:09 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GCONF_BUILDLINK3_MK:=	${GCONF_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	GConf
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:NGConf}
BUILDLINK_PACKAGES+=	GConf

.if !empty(GCONF_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.GConf+=	GConf>=1.0.9nb5
BUILDLINK_PKGSRCDIR.GConf?=	../../devel/GConf

.include "../../databases/db3/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/oaf/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"

.endif	# GCONF_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
