# $NetBSD: rdoc.mk,v 1.18 2014/02/02 07:48:35 taca Exp $

.if !defined(_RUBY_RDOC_MK)
_RUBY_RDOC_MK=	# defined

#
# === Package-settable variables ===
#
# RUBY_RDOC_REQD
#	Specify later version of rdoc.  Ruby base packages contain:
#
#		ruby18-base:	rdoc 1.0.1 - 20041108
#		ruby193-base:	rdoc 3.9.4
#		ruby200-base:	rdoc 4.0.0
#
#	If a package has a trouble with these version, please specify the
#	version of rdoc to RDOC_REQD.
#

.if !empty(RUBY_RDOC_REQD)

RUBY18_RDOC_VERS=	1.0.1
RUBY193_RDOC_VERS=	3.9.4
RUBY200_RDOC_VERS=	4.0.0

_RDOC_REQD_MAJOR=	${RUBY_RDOC_REQD:C/\.[0-9\.]+$//}
_RDOC_REQD_MINORS=	${RUBY_RDOC_REQD:C/^([0-9]+)\.*//}

. if ${RUBY_VER} == "18"
_RUBY_RDOC_MAJOR=	${RUBY18_RDOC_VERS:C/\.[0-9\.]+$//}
_RUBY_RDOC_MINORS=	${RUBY18_RDOC_VERS:C/^([0-9]+)\.*//}
.elif ${RUBY_VER} == "193"
_RUBY_RDOC_MAJOR=	${RUBY193_RDOC_VERS:C/\.[0-9\.]+$//}
_RUBY_RDOC_MINORS=	${RUBY193_RDOC_VERS:C/^([0-9]+)\.*//}
.elif ${RUBY_VER} == "200"
_RUBY_RDOC_MAJOR=	${RUBY200_RDOC_VERS:C/\.[0-9\.]+$//}
_RUBY_RDOC_MINORS=	${RUBY200_RDOC_VERS:C/^([0-9]+)\.*//}
.else
PKG_FAIL_REASON+= "Unknown Ruby version specified: ${RUBY_VER}."
. endif

_RUBY_RDOC_REQD=	NO

. if ${_RDOC_REQD_MAJOR} > ${_RUBY_RDOC_MAJOR}
_RUBY_RDOC_REQD=	YES
. elif ${_RDOC_REQD_MAJOR} == ${_RUBY_RDOC_MAJOR}
.  if !empty(_RUBY_RDOC_MINORS) && ${_RDOC_REQD_MINORS} > ${_RUBY_RDOC_MINORS}
_RUBY_RDOC_REQD=	YES
.  endif
. endif

. if empty(_RUBY_RDOC_REQD:M[nN][oO])
RDOC=			${PREFIX}/bin/rdoc
.  if empty(RUBY_BUILD_RI:M[nN][oO]) && empty(RUBY_BUILD_RDOC:M[nN][oO])
# rdoc will be required at runtime, too.
DEPENDS+= ${RUBY_PKGPREFIX}-rdoc>=${RUBY_RDOC_REQD}:../../devel/ruby-rdoc
.  endif
. endif

.endif
.endif
