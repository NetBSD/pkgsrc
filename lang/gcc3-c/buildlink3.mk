# $NetBSD: buildlink3.mk,v 1.1 2004/02/01 14:05:47 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GCC3C_BUILDLINK3_MK:=	${GCC3C_BUILDLINK3_MK}+

.include "../../mk/bsd.prefs.mk"

.if !empty(GCC3C_BUILDLINK3_MK:M+)
.  if defined(GCC3_INSTALLTO_SUBPREFIX)
GCC3_PKGMODIF=			_${GCC3_INSTALLTO_SUBPREFIX}
.  endif
BUILDLINK_PACKAGES+=		gcc3c
BUILDLINK_DEPENDS+=		gcc3c
BUILDLINK_DEPENDS.gcc3c+=	gcc3${GCC3_PKGMODIF}-c>=${_GCC_REQD}
BUILDLINK_PKGSRCDIR.gcc3c?=	../../lang/gcc3-c

# Packages that link against shared libraries need a full dependency.
.  if defined(USE_GCC_SHLIB)
BUILDLINK_DEPMETHOD.gcc3c+=	full
.  else
BUILDLINK_DEPMETHOD.gcc3c?=	build
.  endif
.endif	# GCC3C_BUILDLINK3_MK

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
