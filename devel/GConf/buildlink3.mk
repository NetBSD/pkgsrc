# $NetBSD: buildlink3.mk,v 1.4 2004/10/03 00:13:24 tv Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GCONF_BUILDLINK3_MK:=	${GCONF_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	GConf
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:NGConf}
BUILDLINK_PACKAGES+=	GConf

.if !empty(GCONF_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.GConf+=	GConf>=1.0.9nb5
BUILDLINK_RECOMMENDED.GConf+=	GConf>=1.0.9nb6
BUILDLINK_PKGSRCDIR.GConf?=	../../devel/GConf
.endif	# GCONF_BUILDLINK3_MK

.include "../../databases/db3/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/oaf/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
