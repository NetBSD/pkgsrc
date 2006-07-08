# $NetBSD: buildlink3.mk,v 1.12 2006/07/08 23:10:54 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GCC_BUILDLINK3_MK:=	${GCC_BUILDLINK3_MK}+

.include "../../mk/bsd.prefs.mk"

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gcc
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngcc}
BUILDLINK_PACKAGES+=	gcc
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}gcc

.if !empty(GCC_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.gcc+=		gcc>=${_GCC_REQD}
BUILDLINK_ABI_DEPENDS.gcc?=	gcc>=2.95.3nb7
BUILDLINK_PKGSRCDIR.gcc?=	../../lang/gcc
BUILDLINK_LIBDIRS.gcc?=		\
	${_GCC_PREFIX:S/^${BUILDLINK_PREFIX.gcc}\///}lib \
	${_GCC_ARCHDIR:S/^${BUILDLINK_PREFIX.gcc}\///}

# Packages that link against shared libraries need a full dependency.
.  if defined(_USE_GCC_SHLIB)
BUILDLINK_DEPMETHOD.gcc+=	full
.  else
BUILDLINK_DEPMETHOD.gcc?=	build
.  endif
.endif	# GCC_BUILDLINK3_MK

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
