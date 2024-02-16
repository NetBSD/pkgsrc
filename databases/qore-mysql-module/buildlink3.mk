# $NetBSD: buildlink3.mk,v 1.16 2024/02/16 20:31:12 nros Exp $
#

BUILDLINK_TREE+=	qore-mysql-module

.if !defined(QORE_MYSQL_MODULE_BUILDLINK3_MK)
QORE_MYSQL_MODULE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qore-mysql-module+=	qore-mysql-module>=2.0.1
BUILDLINK_ABI_DEPENDS.qore-mysql-module?=	qore-mysql-module>=2.1nb8
BUILDLINK_PKGSRCDIR.qore-mysql-module?=		../../databases/qore-mysql-module

.include "../../lang/qore/buildlink3.mk"
.endif	# QORE_MYSQL_MODULE_BUILDLINK3_MK

BUILDLINK_TREE+=	-qore-mysql-module
