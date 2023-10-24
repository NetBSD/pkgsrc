# $NetBSD: buildlink3.mk,v 1.14 2023/10/24 22:10:58 wiz Exp $

BUILDLINK_TREE+=	qore-ssh2-module

.if !defined(QORE_SSH2_MODULE_BUILDLINK3_MK)
QORE_SSH2_MODULE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qore-ssh2-module+=	qore-ssh2-module>=0.9.9
BUILDLINK_ABI_DEPENDS.qore-ssh2-module?=	qore-ssh2-module>=1.4.2nb3
BUILDLINK_PKGSRCDIR.qore-ssh2-module?=		../../security/qore-ssh2-module

.include "../../lang/qore/buildlink3.mk"
.endif	# QORE_SSH2_MODULE_BUILDLINK3_MK

BUILDLINK_TREE+=	-qore-ssh2-module
