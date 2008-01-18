# $NetBSD: buildlink3.mk,v 1.13 2008/01/18 05:14:40 tnn Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
SUBVERSION_BASE_BUILDLINK3_MK:=	${SUBVERSION_BASE_BUILDLINK3_MK}+

.include "../../mk/bsd.fast.prefs.mk"
.include "../../devel/subversion/Makefile.version"

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	subversion-base
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nsubversion-base}
BUILDLINK_PACKAGES+=	subversion-base
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}subversion-base

.if !empty(SUBVERSION_BASE_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.subversion-base+=	subversion-base>=1.0.0
BUILDLINK_ABI_DEPENDS.subversion-base?=	subversion-base>=1.4.6nb3
BUILDLINK_PKGSRCDIR.subversion-base?=	../../devel/subversion-base

BUILDLINK_FILES.subversion-base+=	bin/svn-config

pkgbase := subversion-base
.include "../../mk/pkg-build-options.mk"

.endif	# SUBVERSION_BASE_BUILDLINK3_MK

.if !empty(PKG_BUILD_OPTIONS.subversion-base:Mapr1)
.  include "../../devel/apr/buildlink3.mk"
.  include "../../devel/apr-util/buildlink3.mk"
.  if !empty(PKG_BUILD_OPTIONS.subversion-base:Mserf)
.    include "../../www/serf/buildlink3.mk"
.  else
.    include "../../www/neon/buildlink3.mk"
.  endif
.else
.  include "../../devel/apr0/buildlink3.mk"
.  include "../../www/neon/buildlink3.mk"
.endif

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
