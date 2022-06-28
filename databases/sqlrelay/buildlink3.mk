# $NetBSD: buildlink3.mk,v 1.25 2022/06/28 11:31:38 wiz Exp $

BUILDLINK_TREE+=	sqlrelay

.if !defined(SQLRELAY_BUILDLINK3_MK)
SQLRELAY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.sqlrelay+=	sqlrelay>=1.0.0
BUILDLINK_ABI_DEPENDS.sqlrelay+=	sqlrelay>=1.8.0nb5
BUILDLINK_PKGSRCDIR.sqlrelay?=		../../databases/sqlrelay

.include "../../devel/rudiments/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.endif	# SQLRELAY_BUILDLINK3_MK

BUILDLINK_TREE+=	-sqlrelay
