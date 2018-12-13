# $NetBSD: buildlink3.mk,v 1.14 2018/12/13 19:51:33 adam Exp $

BUILDLINK_TREE+=	sqlrelay

.if !defined(SQLRELAY_BUILDLINK3_MK)
SQLRELAY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.sqlrelay+=	sqlrelay>=1.0.0
BUILDLINK_ABI_DEPENDS.sqlrelay+=	sqlrelay>=1.0.0nb7
BUILDLINK_PKGSRCDIR.sqlrelay?=		../../databases/sqlrelay

.include "../../devel/rudiments/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.endif	# SQLRELAY_BUILDLINK3_MK

BUILDLINK_TREE+=	-sqlrelay
