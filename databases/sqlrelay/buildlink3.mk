# $NetBSD: buildlink3.mk,v 1.27 2023/04/19 08:08:08 adam Exp $

BUILDLINK_TREE+=	sqlrelay

.if !defined(SQLRELAY_BUILDLINK3_MK)
SQLRELAY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.sqlrelay+=	sqlrelay>=1.0.0
BUILDLINK_ABI_DEPENDS.sqlrelay+=	sqlrelay>=1.9.3nb1
BUILDLINK_PKGSRCDIR.sqlrelay?=		../../databases/sqlrelay

.include "../../devel/rudiments/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.endif	# SQLRELAY_BUILDLINK3_MK

BUILDLINK_TREE+=	-sqlrelay
