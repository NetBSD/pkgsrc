# $NetBSD: find-prefix.mk,v 1.4 2005/11/28 05:54:17 jlam Exp $
#
# This is a "subroutine" that can be included to find the installation
# prefix of a package.
#
# The input variable is FIND_PREFIX, which is a list of VARNAME=<pattern>
# pairs, where "VARNAME" is the variable that will be set to the
# installation prefix for the package, and <pattern> is a package
# wildcard pattern used to match the installed package (see pkg_info(8)).
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
	${PKG_INFO} -qp ${_def_:C/^[^=]*=//:Q} 2>/dev/null |		\
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
