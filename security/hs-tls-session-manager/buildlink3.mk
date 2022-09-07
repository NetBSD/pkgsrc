# $NetBSD: buildlink3.mk,v 1.5 2022/09/07 06:50:50 pho Exp $

BUILDLINK_TREE+=	hs-tls-session-manager

.if !defined(HS_TLS_SESSION_MANAGER_BUILDLINK3_MK)
HS_TLS_SESSION_MANAGER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-tls-session-manager+=	hs-tls-session-manager>=0.0.4
BUILDLINK_ABI_DEPENDS.hs-tls-session-manager+=	hs-tls-session-manager>=0.0.4nb4
BUILDLINK_PKGSRCDIR.hs-tls-session-manager?=	../../security/hs-tls-session-manager

.include "../../devel/hs-auto-update/buildlink3.mk"
.include "../../devel/hs-basement/buildlink3.mk"
.include "../../time/hs-clock/buildlink3.mk"
.include "../../devel/hs-memory/buildlink3.mk"
.include "../../devel/hs-psqueues/buildlink3.mk"
.include "../../security/hs-tls/buildlink3.mk"
.endif	# HS_TLS_SESSION_MANAGER_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-tls-session-manager
