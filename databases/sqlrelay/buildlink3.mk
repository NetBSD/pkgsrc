# $NetBSD: buildlink3.mk,v 1.5 2016/10/07 18:25:31 adam Exp $

BUILDLINK_TREE+=	sqlrelay

.if !defined(SQLRELAY_BUILDLINK3_MK)
SQLRELAY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.sqlrelay+=	sqlrelay>=0.43
BUILDLINK_ABI_DEPENDS.sqlrelay+=	sqlrelay>=0.65.0nb2
BUILDLINK_PKGSRCDIR.sqlrelay?=		../../databases/sqlrelay

.include "../../devel/rudiments/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/readline.buildlink3.mk"
.endif	# SQLRELAY_BUILDLINK3_MK

BUILDLINK_TREE+=	-sqlrelay
