# $NetBSD: find-prefix.mk,v 1.6 2008/02/10 10:12:13 rillig Exp $
#
# This is a "subroutine" that can be included to find the installation
# prefix of an installed package.
#
# Parameters:
#
# FIND_PREFIX
#	A list of <VARNAME>=<pattern> pairs, where
#
#	* <pattern> is a package wildcard pattern (see pkg_info(8)),
#	* <VARNAME> is the variable that will be set to the
#	  installation prefix for the package.
#
# Returns:
#
# <VARNAME>
#	The prefix of the corresponding package, or ${LOCALBASE}
#	if the package is not installed.
#
# Example:
#
# FIND_PREFIX:=	M4DIR=gm4
# .include "../../mk/find-prefix.mk"
# # ${M4DIR} now contains the installation prefix for the "gm4" package.
#

.for _def_ in ${FIND_PREFIX}
.  if !defined(${_def_:C/=.*$//})

# XXX: Is this *_DEFAULT variable really necessary? The default value
# can be easily embedded in the shell code. What if VARNAME is set to
# PKG_APACHE, for example?
#
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
