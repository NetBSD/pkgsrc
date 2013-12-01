# $NetBSD: buildlink3.mk,v 1.6 2013/12/01 10:18:02 ryoon Exp $

.include "../../mk/bsd.fast.prefs.mk"
.include "../../devel/subversion/Makefile.version"

BUILDLINK_TREE+=	subversion-base16

.if !defined(SUBVERSION16_BASE_BUILDLINK3_MK)
SUBVERSION16_BASE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.subversion16-base+=	subversion16-base>=1.5.2nb1
BUILDLINK_ABI_DEPENDS.subversion16-base+=	subversion16-base>=1.6.23nb3
BUILDLINK_PKGSRCDIR.subversion16-base?=	../../devel/subversion16-base

BUILDLINK_FILES.subversion16-base+=	bin/svn16-config

pkgbase := subversion16-base
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.subversion16-base:Msasl)
.include "../../security/cyrus-sasl/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.subversion16-base:Mapr1)
.  include "../../devel/apr/buildlink3.mk"
.  include "../../devel/apr-util/buildlink3.mk"
.else
.  include "../../devel/apr0/buildlink3.mk"
.endif

# If serf and -apr1 are selected, the build will probably fail.
# Do that rather than force neon for apr0
.if !empty(PKG_BUILD_OPTIONS.subversion16-base:Mserf)
.  include "../../www/serf0/buildlink3.mk"
.else
.  include "../../www/neon/buildlink3.mk"
.endif

BUILDLINK_API_DEPENDS.sqlite3+=	sqlite3>=3.4
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.endif # SUBVERSION16_BASE_BUILDLINK3_MK

BUILDLINK_TREE+=	-subversion16-base
