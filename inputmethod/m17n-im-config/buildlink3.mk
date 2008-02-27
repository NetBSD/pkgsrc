# $NetBSD: buildlink3.mk,v 1.1.1.1 2008/02/27 14:07:46 obache Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
M17N_IM_CONFIG_BUILDLINK3_MK:=	${M17N_IM_CONFIG_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	m17n-im-config
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nm17n-im-config}
BUILDLINK_PACKAGES+=	m17n-im-config
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}m17n-im-config

.if ${M17N_IM_CONFIG_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.m17n-im-config+=	m17n-im-config>=0.9.0
BUILDLINK_PKGSRCDIR.m17n-im-config?=	../../inputmethod/m17n-im-config
.endif	# M17N_IM_CONFIG_BUILDLINK3_MK

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/m17n-lib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
