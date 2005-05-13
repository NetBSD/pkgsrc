# $NetBSD: find-prefix.mk,v 1.3 2005/05/13 23:37:54 jlam Exp $
#
# This is a "subroutine" that can be included to find the installation
# prefix of a package.
#
# The input variable is FIND_PREFIX, which is a list of VARNAME=<package>
# pairs, where "VARNAME" is the variable that will be set to the
# installation prefix for the package, and <package> is the ${PKGNAME}
# for the package.
#
# An example use is:
#
# FIND_PREFIX:=	M4DIR=gm4
# .include "../../mk/find-prefix.mk"
# # ${M4DIR} now contains the installation prefix for the "gm4" package
#

.for _def_ in ${FIND_PREFIX}
.  if !defined(${_def_:C/=.*$//})
${_def_:C/=.*$//}_DEFAULT?=	${LOCALBASE}
_${_def_:C/=.*$//}_cmd=		\
	${PKG_INFO} -qp ${_def_:C/^.*=//} 2>/dev/null |			\
	{ read cmd arg;							\
	  case "$$arg" in						\
	  "")	${ECHO} ${${_def_:C/=.*$//}_DEFAULT:Q} ;;		\
	  *)	${ECHO} "$$arg" ;;					\
	  esac; }
${_def_:C/=.*$//}=		${_${_def_:C/=.*$//}_cmd:sh}
.  endif
MAKEVARS+=	${_def_:C/=.*$//}
.endfor
.undef _def_
