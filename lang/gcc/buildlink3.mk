# $NetBSD: buildlink3.mk,v 1.7 2004/06/29 13:24:31 gavan Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GCC_BUILDLINK3_MK:=	${GCC_BUILDLINK3_MK}+

.include "../../mk/bsd.prefs.mk"

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gcc
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngcc}
BUILDLINK_PACKAGES+=	gcc

.if !empty(GCC_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.gcc+=		gcc>=${_GCC_REQD}
BUILDLINK_PKGSRCDIR.gcc?=	../../lang/gcc
BUILDLINK_LIBDIRS.gcc?=		\
	${_GCC_PREFIX:S/^${BUILDLINK_PREFIX.gcc}\///}lib \
	${_GCC_ARCHDIR:S/^${BUILDLINK_PREFIX.gcc}\///}

# Packages that link against shared libraries need a full dependency.
.  if defined(USE_GCC_SHLIB)
BUILDLINK_DEPMETHOD.gcc+=	full
.  else
BUILDLINK_DEPMETHOD.gcc?=	build
.  endif
.endif	# GCC_BUILDLINK3_MK

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
