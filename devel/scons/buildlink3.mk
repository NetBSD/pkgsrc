# $NetBSD: buildlink3.mk,v 1.6 2023/08/14 05:24:16 wiz Exp $

# Note that while scons is a build tool, it requires running a python
# program on the host that uses the scons library.  Currently, the
# python version on the host and the version being used on the target
# for the package being built are linked.
# \todo Consider if this can be TOOL_DEPENDS (or TOOL), instead of buildlink.

# scons scripts (SConstruct) have a number of common problems,
# including not passing environment variables set by pkgsrc to
# invocations of the compiler.  See the
# /usr/pkgsrc/*/*/patch-SConstruct for typical remediations.

SCONSBIN=	${PREFIX}/bin/scons

PYTHON_VERSIONS_ACCEPTED+=	27
.include "../../lang/python/pyversion.mk"

BUILDLINK_TREE+=	scons

.if !defined(SCONS_BUILDLINK3_MK)
SCONS_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.scons?=	build
BUILDLINK_API_DEPENDS.scons+=	${PYPKGPREFIX}-scons>=3.0.2<4
BUILDLINK_ABI_DEPENDS.scons?=	${PYPKGPREFIX}-scons>=3.1.2nb7
BUILDLINK_PKGSRCDIR.scons?=	../../devel/scons
.endif	# SCONS_BUILDLINK3_MK

BUILDLINK_TREE+=	-scons
