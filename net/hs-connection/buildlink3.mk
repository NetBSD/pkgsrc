# $NetBSD: buildlink3.mk,v 1.3 2022/01/18 02:48:19 pho Exp $

BUILDLINK_TREE+=	hs-connection

.if !defined(HS_CONNECTION_BUILDLINK3_MK)
HS_CONNECTION_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-connection+=	hs-connection>=0.3.1
BUILDLINK_ABI_DEPENDS.hs-connection+=	hs-connection>=0.3.1nb2
BUILDLINK_PKGSRCDIR.hs-connection?=	../../net/hs-connection

.include "../../devel/hs-basement/buildlink3.mk"
.include "../../devel/hs-data-default-class/buildlink3.mk"
.include "../../net/hs-network/buildlink3.mk"
.include "../../net/hs-socks/buildlink3.mk"
.include "../../security/hs-tls/buildlink3.mk"
.include "../../security/hs-x509/buildlink3.mk"
.include "../../security/hs-x509-store/buildlink3.mk"
.include "../../security/hs-x509-system/buildlink3.mk"
.include "../../security/hs-x509-validation/buildlink3.mk"
.endif	# HS_CONNECTION_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-connection
