# $NetBSD: emacs.mk,v 1.17 2005/03/07 17:48:08 jwise Exp $
#
# A Makefile fragment for Emacs Lisp packages.
#
# 	* Determine the version of Emacs/XEmacs to be used.
#
#	* Emacs Lisp files are installed...
#	  	GNU emacs
#	  		-> ${PREFIX}/share/emacs/site-lisp/foo/...
#		XEmacs
#	  		->${PREFIX}/lib/xemacs/site-packages/lisp/foo/...
#
#	* XEmacs package's names are prefix'ed by "xemacs-", since Emacs
#	  {20,21} conflict, and XEmacs conflict.
#
#	* Assume each package supports GNU Emacs {20,21} by default.  If the
#	  package supports XEmacsen too, define EMACS_VERSIONS_ACCEPTED
#	  explicitly before including mk/emacs.mk.  Note that the order is
#	  important.
#

.if !defined(EMACS_MK)
EMACS_MK=	# defined

.include "../../mk/bsd.prefs.mk"

# Assume only GNU emacsen are supported by default.
#
EMACS_VERSION_DEFAULT?=		emacs21
.if !defined(USE_XEMACS)
EMACS_VERSIONS_ACCEPTED?=	emacs21 emacs21nox emacs20
#EMACS_VERSIONS_ACCEPTED?=	emacs21 emacs21nox xemacs214 emacs20 xemacs215
.else
EMACS_VERSIONS_ACCEPTED?=	xemacs214 xemacs215
.endif

# Actually BUILDLINK_ means little here...
#
BUILDLINK_DEPENDS.emacs20?=	emacs>=20.7
BUILDLINK_DEPENDS.emacs21?=	emacs>=21.2
BUILDLINK_DEPENDS.emacs21nox?=	emacs-nox11>=21.2
BUILDLINK_DEPENDS.xemacs214?=	xemacs>=21.4
BUILDLINK_DEPENDS.xemacs215?=	xemacs>=21.5
BUILDLINK_DEPENDS.leim20?=	leim>=20.7
BUILDLINK_DEPENDS.leim21?=	leim>=21.2

.for v in ${EMACS_VERSIONS_ACCEPTED}
_EMACS_VERSION_${v}_OK=	yes
.endfor

# Look for Emacs 21/Emacs 20
#
_TMP!=	${PKG_INFO} -e emacs || ${ECHO}
.if ${_TMP} != ""
_EMACS_VERSION_EMACS_FULL:=	${_TMP}
_EMACS_VERSION_EMACS=	${_EMACS_VERSION_EMACS_FULL:C/^.*-//}
_EMACS_VERSION_EMACS_MAJOR=	${_EMACS_VERSION_EMACS:C/\..*//}
.if ${_EMACS_VERSION_EMACS_MAJOR} == "21"
_EMACS_VERSION_emacs21_INSTALLED=	yes
.elif ${_EMACS_VERSION_EMACS_MAJOR} == "20"
_EMACS_VERSION_emacs20_INSTALLED=	yes
.endif
.endif

# Look for Emacs21 without X11
#
_TMP!= ${PKG_INFO} -e emacs-nox11 || ${ECHO}
.if ${_TMP} != ""
_EMACS_VERSION_EMACS_FULL:=	${_TMP}
_EMACS_VERSION_EMACS=	${_EMACS_VERSION_EMACS_FULL:C/^.*-//}
_EMACS_VERSION_EMACS_MAJOR=	${_EMACS_VERSION_EMACS:C/\..*//}
_EMACS_VERSION_emacs21nox_INSTALLED=	yes
.endif

# Look for XEmacs 21.5/XEmacs 21.1
#
_TMP!=	${PKG_INFO} -e xemacs || ${ECHO}
.if ${_TMP} != ""
_EMACS_VERSION_XEMACS_FULL:=	${_TMP:C/^.*-//}
_EMACS_VERSION_XEMACS=	${_EMACS_VERSION_XEMACS_FULL:C/^.*-//}
_EMACS_VERSION_XEMACS_MAJOR=	${_EMACS_VERSION_XEMACS:C/\..*//}
_EMACS_VERSION_XEMACS_MINOR=	${_EMACS_VERSION_XEMACS:C/^[0-9]*\.//:C/[^0-9].*//}
.if ${_EMACS_VERSION_XEMACS_MAJOR} == "21" && \
	${_EMACS_VERSION_XEMACS_MINOR} == "5"
_EMACS_VERSION_xemacs215_INSTALLED=	yes
.elif ${_EMACS_VERSION_XEMACS_MAJOR} == "21" && \
	${_EMACS_VERSION_XEMACS_MINOR} == "4"
_EMACS_VERSION_xemacs214_INSTALLED=	yes
.endif
.endif

# Determine the Emacs version to be used.
#
.if defined(EMACS_VERSION_REQD)
_EMACS_VERSION=	${EMACS_VERSION_REQD}
.endif
.if !defined(_EMACS_VERSION)
.if defined(_EMACS_VERSION_${EMACS_VERSION_DEFAULT}_OK)
.if defined(_EMACS_VERSION_${EMACS_VERSION_DEFAULT}_INSTALLED)
_EMACS_VERSION=	${EMACS_VERSION_DEFAULT}
.endif
.endif
.endif
.if !defined(_EMACS_VERSION)
.for v in ${EMACS_VERSIONS_ACCEPTED}
.if defined(_EMACS_VERSION_${v}_INSTALLED)
_EMACS_VERSION?=	${v}
.else
_EMACS_VERSION_FIRSTACCEPTED?=	${v}
.endif
.endfor
.endif
.if !defined(_EMACS_VERSION)
.if defined(_EMACS_VERSION_${EMACS_VERSION_DEFAULT}_OK)
_EMACS_VERSION=	${EMACS_VERSION_DEFAULT}
.endif
.endif
.if !defined(_EMACS_VERSION)
_EMACS_VERSION=	${_EMACS_VERSION_FIRSTACCEPTED}
.endif

# Set version specifics.
#
FOR.emacs21=		"@comment "
FOR.emacs21nox=		"@comment "
FOR.emacs20=		"@comment "
FOR.xemacs215=		"@comment "
FOR.xemacs214=		"@comment "
.if ${_EMACS_VERSION} == "emacs21"
EMACS_DEPENDENCY=	${BUILDLINK_DEPENDS.emacs21}:../../editors/emacs
FOR.emacs21=		""
.if defined(EMACS_USE_LEIM)
DEPENDS+=		${BUILDLINK_DEPENDS.leim21}:../../editors/leim
.endif
.elif ${_EMACS_VERSION} == "emacs21nox"
EMACS_DEPENDENCY=	${BUILDLINK_DEPENDS.emacs21nox}:../../editors/emacs-nox11
FOR.emacs21nox=		""
.if defined(EMACS_USE_LEIM)
DEPENDS+=		${BUILDLINK_DEPENDS.leim21}:../../editors/leim
.endif
.elif ${_EMACS_VERSION} == "emacs20"
EMACS_DEPENDENCY=	${BUILDLINK_DEPENDS.emacs20}:../../editors/emacs20
FOR.emacs20=		""
.if defined(EMACS_USE_LEIM)
DEPENDS+=		${BUILDLINK_DEPENDS.leim20}:../../editors/leim20
.endif
.elif ${_EMACS_VERSION} == "xemacs215"
EMACS_DEPENDENCY=	${BUILDLINK_DEPENDS.xemacs215}:../../editors/xemacs-current
FOR.xemacs215=		""
.elif ${_EMACS_VERSION} == "xemacs214"
EMACS_DEPENDENCY=	${BUILDLINK_DEPENDS.xemacs214}:../../editors/xemacs
FOR.xemacs214=		""
.else
PKG_SKIP_REASON+=	"Accepted versions are: ${EMACS_VERSIONS_ACCEPTED}"
PKG_SKIP_REASON+=	"No valid Emacs version installed found"
.endif
.if defined(EMACS_FOR_BUILD_ONLY)
BUILD_DEPENDS+=	${EMACS_DEPENDENCY}
.else
DEPENDS+=	${EMACS_DEPENDENCY}
.endif

# Provide some macro definitions.
#
.if ${_EMACS_VERSION:Memacs*}
EMACS_FLAVOR=	emacs
EMACS_BIN=	${PREFIX}/bin/emacs
EMACS_PKG_VERSION=	${_EMACS_VERSION_EMACS_FULL:C|^.*-||}
EMACS_LISPPREFIX=	${PREFIX}/share/emacs/site-lisp
PKGNAME_PREFIX=
CONFLICTS+=		xemacs-${PKGBASE}-[0-9]*
.else
EMACS_FLAVOR=	xemacs
EMACS_BIN=	${PREFIX}/bin/xemacs
EMACS_PKG_VERSION=	${_EMACS_VERSION_XEMACS_FULL:C|^.*-||}
EMACS_LISPPREFIX=	${PREFIX}/lib/xemacs/site-packages/lisp
PKGNAME_PREFIX=		xemacs-
PKGNAME:=		${PKGNAME_PREFIX}${PKGNAME}
CONFLICTS+=		${PKGBASE:C|^xemacs-||}-[0-9]*
.endif
# strip out nb?
EMACS_VERSION=${EMACS_PKG_VERSION:C|nb[0-9]*$||}
PLIST_SUBST+=	EMACS_VERSION=${EMACS_VERSION}
PLIST_SUBST+=	EMACS_LISPPREFIX=${EMACS_LISPPREFIX:C|^${PREFIX}/||}
PLIST_SUBST+=	FOR_emacs21=${FOR.emacs21}
PLIST_SUBST+=	FOR_emacs21nox=${FOR.emacs21nox}
PLIST_SUBST+=	FOR_emacs20=${FOR.emacs20}
PLIST_SUBST+=	FOR_xemacs215=${FOR.xemacs215}
PLIST_SUBST+=	FOR_xemacs214=${FOR.xemacs214}

_REPLACE_EMACS_SED=	-e "1s;^\#!.*emacs;\#!${EMACS_BIN};"

.if defined(REPLACE_EMACS)
emacs-patch-scripts:
.for s in ${REPLACE_EMACS}
	${CP} ${WRKSRC}/$s ${WRKSRC}/${s}.tmp
	${CHMOD} +w ${WRKSRC}/$s
	${SED} ${_REPLACE_EMACS_SED} <${WRKSRC}/${s}.tmp >${WRKSRC}/$s
.endfor

post-patch: emacs-patch-scripts
.endif

.endif	# EMACS_MK
