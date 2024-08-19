# $NetBSD: buildlink3.mk,v 1.5 2024/08/19 11:55:25 adam Exp $

BUILDLINK_TREE+=	groonga

.if !defined(GROONGA_BUILDLINK3_MK)
GROONGA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.groonga+=	groonga>=7.0.4
BUILDLINK_ABI_DEPENDS.groonga+=	groonga>=7.0.6nb4
BUILDLINK_PKGSRCDIR.groonga?=	../../textproc/groonga
BUILDLINK_INCDIRS.groonga+=	include/groonga

.include "../../devel/editline/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"

pkgbase := groonga
.include "../../mk/pkg-build-options.mk"

.if ${PKG_BUILD_OPTIONS.groonga:Mgroonga-suggest-learner}
.include "../../devel/msgpack/buildlink3.mk"
.endif

.if ${PKG_BUILD_OPTIONS.groonga:Mlz4}
.include "../../archivers/lz4/buildlink3.mk"
.endif

.if ${PKG_BUILD_OPTIONS.groonga:Mmecab}
.include "../../textproc/mecab/buildlink3.mk"
.endif

.endif	# GROONGA_BUILDLINK3_MK

BUILDLINK_TREE+=	-groonga
