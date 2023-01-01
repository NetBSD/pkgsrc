# $NetBSD: buildlink3.mk,v 1.1 2023/01/01 00:44:35 mef Exp $

BUILDLINK_TREE+=	R-cli

.if !defined(R_CLI_BUILDLINK3_MK)
R_CLI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.R-cli+=	R-cli>=3.4.0
BUILDLINK_PKGSRCDIR.R-cli?=	../../devel/R-cli
.endif	# R_CLI_BUILDLINK3_MK

BUILDLINK_TREE+=	-R-cli
