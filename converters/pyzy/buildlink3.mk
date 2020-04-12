# $NetBSD: buildlink3.mk,v 1.16 2020/04/12 08:27:49 adam Exp $
#

BUILDLINK_TREE+=	pyzy

.if !defined(PYZY_BUILDLINK3_MK)
PYZY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.pyzy+=	pyzy>=0.1.0
BUILDLINK_ABI_DEPENDS.pyzy?=	pyzy>=0.1.0nb15
BUILDLINK_PKGSRCDIR.pyzy?=	../../converters/pyzy

.include "../../mk/bsd.fast.prefs.mk"

.if ${OPSYS} == "Linux" || ${OPSYS} == "SunOS"
.  include "../../devel/libuuid/buildlink3.mk"
.endif

.include "../../devel/glib2/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.endif	# PYZY_BUILDLINK3_MK

BUILDLINK_TREE+=	-pyzy
