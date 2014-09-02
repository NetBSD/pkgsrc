# $NetBSD: buildlink3.mk,v 1.1 2014/09/02 14:12:39 mef Exp $

BUILDLINK_TREE+=	cheetah

.if !defined(CHEETAH_BUILDLINK3_MK)
CHEETAH_BUILDLINK3_MK:=

.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.cheetah+=	${PYPKGPREFIX}-cheetah>=2.4
BUILDLINK_PKGSRCDIR.cheetah?=	../../devel/py-cheetah
.endif	# CHEETAH_BUILDLINK3_MK

BUILDLINK_TREE+=	-cheetah
