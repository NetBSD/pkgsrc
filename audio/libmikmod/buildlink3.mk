# $NetBSD: buildlink3.mk,v 1.8 2006/02/05 23:08:11 joerg Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBMIKMOD_BUILDLINK3_MK:=	${LIBMIKMOD_BUILDLINK3_MK}+

.include "../../mk/bsd.prefs.mk"

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libmikmod
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibmikmod}
BUILDLINK_PACKAGES+=	libmikmod

.if !empty(LIBMIKMOD_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.libmikmod+=	libmikmod>=3.1.9
BUILDLINK_RECOMMENDED.libmikmod+=	libmikmod>=3.1.11.1nb2
BUILDLINK_PKGSRCDIR.libmikmod?=	../../audio/libmikmod
.endif	# LIBMIKMOD_BUILDLINK3_MK

.if !defined(PKG_BUILD_OPTIONS.libmikmod)
PKG_BUILD_OPTIONS.libmikmod!=	cd ${BUILDLINK_PKGSRCDIR.libmikmod} && \
			${MAKE} show-var ${MAKEFLAGS} VARNAME=PKG_OPTIONS
MAKEFLAGS+=	PKG_BUILD_OPTIONS.libmikmod=${PKG_BUILD_OPTIONS.libmikmod:Q}
.endif
MAKEVARS+=	PKG_BUILD_OPTIONS.libmikmod

# On some platforms, libmikmod dynamically loads esound,
# so there is no library dependency
.if !empty(PKG_BUILD_OPTIONS.libmikmod:Mesound) && \
  empty(OPSYS:MNetBSD) && empty(OPSYS:MLinux)
.  include "../../audio/esound/buildlink3.mk"
.endif

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
