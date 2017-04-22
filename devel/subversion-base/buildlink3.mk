# $NetBSD: buildlink3.mk,v 1.46 2017/04/22 21:03:11 adam Exp $

.include "../../mk/bsd.fast.prefs.mk"
.include "../../devel/subversion/Makefile.version"

BUILDLINK_TREE+=	subversion-base

.if !defined(SUBVERSION_BASE_BUILDLINK3_MK)
SUBVERSION_BASE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.subversion-base+=	subversion-base>=1.5.2nb1
BUILDLINK_ABI_DEPENDS.subversion-base+=	subversion-base>=1.9.5nb2
BUILDLINK_PKGSRCDIR.subversion-base?=	../../devel/subversion-base

BUILDLINK_FILES.subversion-base+=	bin/svn-config

pkgbase := subversion-base
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.subversion-base:Msasl)
.include "../../security/cyrus-sasl/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.subversion-base:Mserf)
.  include "../../www/serf/buildlink3.mk"
.endif

BUILDLINK_API_DEPENDS.sqlite3+=	sqlite3>=3.7.15.1
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/apr/buildlink3.mk"
.include "../../devel/apr-util/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.endif # SUBVERSION_BASE_BUILDLINK3_MK

BUILDLINK_TREE+=	-subversion-base
