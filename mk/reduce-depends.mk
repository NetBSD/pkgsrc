# $NetBSD: reduce-depends.mk,v 1.1 2004/10/05 15:28:50 jlam Exp $
#
# Copyright (c) 2004 The NetBSD Foundation, Inc.
# All rights reserved.
#
# This code is derived from software contributed to The NetBSD Foundation
# by Johnny C. Lam.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
# 1. Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
# 2. Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in the
#    documentation and/or other materials provided with the distribution.
# 3. All advertising materials mentioning features or use of this software
#    must display the following acknowledgement:
#        This product includes software developed by the NetBSD
#        Foundation, Inc. and its contributors.
# 4. Neither the name of The NetBSD Foundation nor the names of its
#    contributors may be used to endorse or promote products derived
#    from this software without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS
# ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
# TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
# PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS
# BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
# CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
# SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
# INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
# CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
# ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# POSSIBILITY OF SUCH DAMAGE.
#

# This Makefile fragment takes the dependencies listed in ${DEPENDS} and
# creates a smaller set of dependencies in ${REDUCED_DEPENDS} that imply
# the same dependency relationships as ${DEPENDS}.

# We skip the dependency calculation for some phases since they never
# use the dependency information.  In these cases, ${REDUCED_DEPENDS}
# is simply empty.
#
_PHASES_SKIP_DEPENDS=	fetch patch tools wrapper configure build test
.if !empty(_PHASES_SKIP_DEPENDS:M${PKG_PHASE})
_DEPENDS=	# empty
.else
_DEPENDS=	${DEPENDS}
.endif

# _DEPENDS_PKGPATHS contains the full physical paths to the pkgsrc
#	directories for dependencies.
# _DEPENDS_PKGPATH.<relpkgpath> maps <relpkgpath> to the full physical path.
# _DEPENDS.<physpkgpath> is a list of the wildcard dependencies associated
#	with <physpkgpath>.
#
_DEPENDS_PKGPATHS=	# empty
.for _dep_ in ${_DEPENDS}
.  if !defined(_DEPENDS_PKGPATH.${_dep_:C/^[^:]*://:C/:.*$//})
_DEPENDS_PKGPATH.${_dep_:C/^[^:]*://:C/:.*$//}!=			\
	cd ${_dep_:C/^[^:]*://:C/:.*$//} && ${PWD_CMD}
.  endif
_DEPENDS_PKGPATH.${_DEPENDS_PKGPATH.${_dep_:C/^[^:]*://:C/:.*$//}}?=	\
	${_dep_:C/^[^:]*://:C/:.*$//}
_DEPENDS.${_DEPENDS_PKGPATH.${_dep_:C/^[^:]*://:C/:.*$//}}+=		\
	${_dep_:C/:.*$//}
.  if empty(_DEPENDS_PKGPATHS:M${_DEPENDS_PKGPATH.${_dep_:C/^[^:]*://:C/:.*$//}})
_DEPENDS_PKGPATHS+=	${_DEPENDS_PKGPATH.${_dep_:C/^[^:]*://:C/:.*$//}}
.  endif
.endfor

# This next block of code sets REDUCED_DEPENDS to the strictest set of
# dependencies it can derive from all of ${_DEPENDS.<path>}.  It only
# understands dependencies of the form foo>=1.0, and leaves the other
# dependencies undisturbed.
#
# The algorithm takes dependencies of the form foo>=1.0 and converts
# them to foo-1.0.  It then compares this pkg name against each
# dependency to see if it satisfies them all.  The key fact is the
# the strictest dependency, when converted to a pkg name, will satisfy
# every dependency.
#
REDUCED_DEPENDS=	# empty
.for _path_ in ${_DEPENDS_PKGPATHS}
_GE_DEPENDS.${_path_}=		${_DEPENDS.${_path_}:N*\{*:M*>=[0-9]*}
_STRICTEST_DEPENDS.${_path_}?=	none
.  for _depend_ in ${_GE_DEPENDS.${_path_}}
.    for _dep2pkg_ in ${_depend_:S/>=/-/}
.      if ${_STRICTEST_DEPENDS.${_path_}} == "none"
_SATISFIES_DEPENDS.${_path_}=	YES
.        for _dep_ in ${_GE_DEPENDS.${_path_}}
.          if !empty(_SATISFIES_DEPENDS.${_path_}:M[yY][eE][sS])
_SATISFIES_DEPENDS.${_path_}!=						\
	if ${PKG_ADMIN} pmatch '${_dep_}' ${_dep2pkg_}; then		\
		${ECHO} "YES";						\
	else								\
		${ECHO} "NO";						\
	fi
.          endif
.        endfor
.        if !empty(_SATISFIES_DEPENDS.${_path_}:M[yY][eE][sS])
_STRICTEST_DEPENDS.${_path_}=	${_depend_}
.        endif
.      endif
.    endfor
.  endfor
.  if ${_STRICTEST_DEPENDS.${_path_}} == "none"
#
# The dependencies simply conflict, so just pass them on through to the
# normal dependency handling code.
#
REDUCED_DEPENDS+=	${_DEPENDS.${_path_}}:${_DEPENDS_PKGPATH.${_path_}}
.  else
.    for _depend_ in ${_DEPENDS.${_path_}}
.      if empty(_GE_DEPENDS.${_path_}:M${_depend_})
REDUCED_DEPENDS+=	${_depend_}:${_DEPENDS_PKGPATH.${_path_}}
.      endif
.    endfor
REDUCED_DEPENDS+=	${_STRICTEST_DEPENDS.${_path_}}:${_DEPENDS_PKGPATH.${_path_}}
.  endif
.endfor
