# $NetBSD: buildlink3.mk,v 1.13 2006/07/08 23:10:36 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBMIKMOD_BUILDLINK3_MK:=	${LIBMIKMOD_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	libmikmod
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibmikmod}
BUILDLINK_PACKAGES+=	libmikmod
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libmikmod

.if ${LIBMIKMOD_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.libmikmod+=	libmikmod>=3.1.9
BUILDLINK_ABI_DEPENDS.libmikmod+=	libmikmod>=3.1.11.1nb2
BUILDLINK_PKGSRCDIR.libmikmod?=	../../audio/libmikmod

.  include "../../mk/bsd.prefs.mk"
.  if !defined(PKG_BUILD_OPTIONS.libmikmod)
PKG_BUILD_OPTIONS.libmikmod!=	cd ${BUILDLINK_PKGSRCDIR.libmikmod} && \
			${MAKE} show-var ${MAKEFLAGS} VARNAME=PKG_OPTIONS
MAKEFLAGS+=	PKG_BUILD_OPTIONS.libmikmod=${PKG_BUILD_OPTIONS.libmikmod:Q}
.  endif
MAKEVARS+=	PKG_BUILD_OPTIONS.libmikmod

# On some platforms, libmikmod dynamically loads esound,
# so there is no library dependency
.  if !empty(PKG_BUILD_OPTIONS.libmikmod:Mesound) && \
  empty(OPSYS:MNetBSD) && empty(OPSYS:MLinux)
.    include "../../audio/esound/buildlink3.mk"
.  endif
.endif	# LIBMIKMOD_BUILDLINK3_MK

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
