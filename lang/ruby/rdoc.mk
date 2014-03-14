# $NetBSD: rdoc.mk,v 1.20 2014/03/14 19:33:10 taca Exp $

.if !defined(_RUBY_RDOC_MK)
_RUBY_RDOC_MK=	# defined

#
# === Package-settable variables ===
#
# RUBY_RDOC_REQD
#	Specify minimum version of rdoc.
#

.if !empty(RUBY_RDOC_REQD)

. if empty(RUBY_VER)
.   include "../../lang/ruby/rubyversion.mk"
. endif

_RDOC_REQD_MAJOR=	${RUBY_RDOC_REQD:C/\.[0-9\.]+$//}
_RDOC_REQD_MINORS=	${RUBY_RDOC_REQD:C/^([0-9]+)\.*//}

_RUBY_RDOC_MAJOR=	${RUBY_RDOC_VERSION:C/\.[0-9\.]+$//}
_RUBY_RDOC_MINORS=	${RUBY_RDOC_VERSION:C/^([0-9]+)\.*//}

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
