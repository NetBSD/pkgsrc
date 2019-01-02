# $NetBSD: buildlink3.mk,v 1.1 2019/01/02 17:18:47 tnn Exp $

SCONSBIN=	${PREFIX}/bin/scons

.include "../../lang/python/pyversion.mk"

BUILDLINK_TREE+=	scons

.if !defined(SCONS_BUILDLINK3_MK)
SCONS_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.scons?=	build
BUILDLINK_API_DEPENDS.scons+=	${PYPKGPREFIX}-scons>=3.0.2
BUILDLINK_PKGSRCDIR.scons?=	../../devel/scons
.endif	# SCONS_BUILDLINK3_MK

BUILDLINK_TREE+=	-scons
