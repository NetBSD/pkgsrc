# $NetBSD: buildlink3.mk,v 1.13 2018/12/09 18:51:58 adam Exp $
#

BUILDLINK_TREE+=	pyzy

.if !defined(PYZY_BUILDLINK3_MK)
PYZY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.pyzy+=	pyzy>=0.1.0
BUILDLINK_ABI_DEPENDS.pyzy?=	pyzy>=0.1.0nb12
BUILDLINK_PKGSRCDIR.pyzy?=	../../converters/pyzy

.include "../../mk/bsd.fast.prefs.mk"

.if ${OPSYS} == "Linux" || ${OPSYS} == "SunOS"
.  include "../../devel/libuuid/buildlink3.mk"
.endif

.include "../../devel/glib2/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.endif	# PYZY_BUILDLINK3_MK

BUILDLINK_TREE+=	-pyzy
