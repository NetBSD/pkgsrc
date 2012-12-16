# $NetBSD: buildlink3.mk,v 1.28 2012/12/16 01:52:12 obache Exp $

.include "../../mk/bsd.fast.prefs.mk"
.include "../../devel/subversion/Makefile.version"

BUILDLINK_TREE+=	subversion-base

.if !defined(SUBVERSION_BASE_BUILDLINK3_MK)
SUBVERSION_BASE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.subversion-base+=	subversion-base>=1.5.2nb1
BUILDLINK_ABI_DEPENDS.subversion-base+=	subversion-base>=1.6.17nb6
BUILDLINK_PKGSRCDIR.subversion-base?=	../../devel/subversion-base

BUILDLINK_FILES.subversion-base+=	bin/svn-config

pkgbase := subversion-base
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.subversion-base:Msasl)
.include "../../security/cyrus-sasl/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.subversion-base:Mapr1)
.  include "../../devel/apr/buildlink3.mk"
.  include "../../devel/apr-util/buildlink3.mk"
.else
.  include "../../devel/apr0/buildlink3.mk"
.endif

# If serf and -apr1 are selected, the build will probably fail.
# Do that rather than force neon for apr0
.if !empty(PKG_BUILD_OPTIONS.subversion-base:Mserf)
.  include "../../www/serf/buildlink3.mk"
.else
.  include "../../www/neon/buildlink3.mk"
.endif

BUILDLINK_API_DEPENDS.sqlite3+=	sqlite3>=3.4
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.endif # SUBVERSION_BASE_BUILDLINK3_MK

BUILDLINK_TREE+=	-subversion-base
