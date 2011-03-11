# $NetBSD: buildlink3.mk,v 1.9 2011/03/11 20:04:46 gdt Exp $

BUILDLINK_TREE+=	rvm

.if !defined(RVM_BUILDLINK3_MK)
RVM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.rvm+=	rvm>=1.3
BUILDLINK_ABI_DEPENDS.rvm+=	rvm>=1.17
BUILDLINK_PKGSRCDIR.rvm?=	../../devel/rvm

.include "../../devel/lwp/buildlink3.mk"
.endif # RVM_BUILDLINK3_MK

BUILDLINK_TREE+=	-rvm
