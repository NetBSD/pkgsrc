# $NetBSD: emacs.mk,v 1.23 2005/12/05 22:07:07 rillig Exp $
#
# This Makefile fragment handles Emacs Lisp Packages (== ELPs).
#
# Note to users:
#
#	* Users choose one favoriate Emacs version (default GNU Emacs 21).
#
#	* Emacs Lisp files are installed...
#	  	GNU emacs
#	  		-> ${PREFIX}/share/emacs/site-lisp/foo/...
#		XEmacs
#	  		->${PREFIX}/lib/xemacs/site-packages/lisp/foo/...
#
#	* You can't install an ELP for both Emacs and XEmacs
#	  simultaneously.
#
#	* XEmacs package's names are prefix'ed by "xemacs-".
#
# Note to package developers:
#
#	* XEmacs package's names are prefix'ed by "xemacs-".
#
#	  This is to make sure ELPs for XEmacs keep their own dependency
#	  tree (for example, if an ELP "bar" depends on another ELP "foo",
#	  "xemacs-bar" depends on "xemacs-foo".  "foo" (installed for GNU
#	  Emacs) is useless for "xemacs-bar" in this case.).
#
#	  Make sure too that "foo" and "xemacs-foo" conflict each other,
#	  since they can share some files.  (Making all ELPs separately
#	  installable for GNU Emacs/XEmacs might be possible.)
#
#	* Assume each ELP supports all Emacs versions by default.  If the
#	  ELP supports only certain Emacs versions, define EMACS_VERSIONS
#	  _ACCEPTED explicitly before including mk/emacs.mk.
#
# Variables for users:
#
#	EMACS_TYPE
#		Description:
#			The user's favoriate Emacs version.
#		Possible values:
#			emacs21, emacs21nox, emacs20, xemacs215, xemacs214
#		Default value:
#			emacs21
#
# Variables ELPs can provide:
#
#	EMACS_USE_LEIM
#		Description:
#			Set if the ELP wants LEIM support.
#		Possible values:
#			<undefined>, <defined>
#		Default value:
#			<undefined>
#
#	EMACS_VERSIONS_ACCEPTED
#		Description:
#			Versions the ELP accepts (supports).
#		Possible values:
#			emacs21, emacs21nox, emacs20, xemacs215, xemacs214
#		Default value:
#			emacs21, emacs21nox, emacs20, xemacs215, xemacs214
#	REPLACE_EMACS
#		Description:
#			If set, correct the #!/path/to/emacs line in the
#			specified files.
#		Possible values:
#			<a list of files relative to ${WRKDIR}>
#		Default value:
#			<undefined>
#
# Variables provided for ELPs:
#
#	EMACS_BIN
#		Description:
#			Path to Emacs executable.
#		Possible values:
#			${PREFIX}/bin/emacs, ${PREFIX}/bin/xemacs
#
#	EMACS_ETCPREFIX
#		Description:
#			Path to the directory misc. files should be
#			installed into.  ELPs should append a short
#			name as a subdirectory.
#		Possible values:
#			${PREFIX}/share
#	  		${PREFIX}/lib/xemacs/site-packages/etc
#
#	EMACS_FLAVOR
#		Description:
#			GNU Emacs (emacs) or XEmacs (xemacs).
#		Possible values:
#			emacs, xemacs
#
#	EMACS_INFOPREFIX
#		Description:
#			Path to the directory Info files should be
#			installed into.  Unlike EMACS_ETCPREFIX or
#			EMACS_LISPPREFIX, subdirectory is not needed.
#		Possible values:
#			${PREFIX}/info
#	  		${PREFIX}/lib/xemacs/site-packages/info
#
#	EMACS_LISPPREFIX
#		Description:
#			Path to the directory Emacs lisp files should be
#			installed into.  ELPs should append a short name
#			as a subdirectory.
#		Possible values:
#			${PREFIX}/share/emacs/site-lisp
#	  		${PREFIX}/lib/xemacs/site-packages/lisp
#
#	EMACS_PKGNAME_PREFIX
#		Description:
#			The prefix of PKGNAME and DEPENDS lines.  All ELPs
#			must honour this!
#		Possible values:
#			"", "xemacs-"
#
# Variables provided in ELPs' PLIST:
#
#	EMACS_ETCPREFIX
#		Description:
#			Same as the one in Makefile, except that
#			${PREFIX} is omitted in PLIST.
#		Possible values:
#			share
#	  		lib/xemacs/site-packages/etc
#
#	EMACS_INFOPREFIX
#		Description:
#			Same as the one in Makefile, except that
#			${PREFIX} is omitted in PLIST.
#		Possible values:
#			info
#	  		lib/xemacs/site-packages/info
#
#	EMACS_LISPPREFIX
#		Description:
#			Same as the one in Makefile, except that
#			${PREFIX} is omitted in PLIST.
#		Possible values:
#			share/emacs/site-lisp
#	  		lib/xemacs/site-packages/lisp
#
#	EMACS_VERSION
#		Description:
#			XXX
#		Possible values:
#			XXX
#
#	FOR_{emacs,emacs21,emacs21nox,emacs20,xemacs,xemacs215,xemacs214}
#		Description:
#			These macros will become either an empty string or
#			"@comment" depending on the Emacs version; when
#			"emacs21" is used, ${FOR_emacs} and ${FOR_emacs21}
#			become "" (empty), and other macros become
#			"@comment"; thie means that only the PLIST lines
#			prefixed by ${FOR_emacs} and ${FOR_emacs21} are
#			valid.
#		Possible values:
#			"", "@comment"
#
#	NOTFOR_{emacs,emacs21,emacs21nox,emacs20,xemacs,xemacs215,xemacs214}
#		Description:
#			The opposite of FOR_*.  See above.
#		Possible values:
#			"", "@comment"
#

.if !defined(EMACS_MK)
EMACS_MK=	# defined

.include "../../mk/bsd.prefs.mk"

#
# Constants
#

_EMACS_VERSIONS_ALL= \
	emacs21 emacs21nox xemacs214 emacs20 xemacs215
_EMACS_VERSIONS_ACCEPTED_DEFAULT=	${_EMACS_VERSIONS_ALL}
_EMACS_VERSION_DEFAULT.emacs=	emacs21
_EMACS_VERSION_DEFAULT.xemacs=	xemacs214
_EMACS_REQD.emacs20=	emacs>=20.7
_EMACS_REQD.emacs21=	emacs>=21.2
_EMACS_REQD.emacs21nox=	emacs-nox11>=21.2
_EMACS_REQD.xemacs214=	xemacs>=21.4
_EMACS_REQD.xemacs215=	xemacs>=21.5
_EMACS_REQD.leim20=	leim>=20.7
_EMACS_REQD.leim21=	leim>=21.2
_EMACS_DEP.emacs20=	../../editors/emacs20
_EMACS_DEP.emacs21=	../../editors/emacs
_EMACS_DEP.emacs21nox=	../../editors/emacs-nox11
_EMACS_DEP.xemacs214=	../../editors/xemacs
_EMACS_DEP.xemacs215=	../../editors/xemacs-current
_EMACS_DEP.leim20=	../../editors/leim20
_EMACS_DEP.leim21=	../../editors/leim

#
# Version decision
#
# 1. Pick up an emacs version.
#
#	if (user want a specific version)
#		if (the specified version is "emacs" or "xemacs")
#			fall into recommended versions (i.e. "emacs21" or
#			    "xemacs214";
#		use the specified version;
#	else
#		use "emacs21" by default;
#	add a dependency to the version;
#
# 2. Check if a given package can be used for the emacs version.
#
# 	if (package accepts the emacs version)
#		nothing to do;
#	else
#		abort;
#

.if !empty(EMACS_TYPE:Memacs) || !empty(EMACS_TYPE:Mxemacs)
_EMACS_TYPE=	${_EMACS_VERSION_DEFAULT.${EMACS_TYPE}}
.endif
_EMACS_TYPE?=	${EMACS_TYPE}

.if !empty(_EMACS_TYPE:Nxemacs*)
.  if !empty(_EMACS_TYPE:N*nox)
_EMACS_PKGBASE=	emacs
.  else
_EMACS_PKGBASE=	emacs-nox11
.  endif
.else
.  if !empty(_EMACS_TYPE:N*nox)
_EMACS_PKGBASE=	xemacs
.  else
_EMACS_PKGBASE=	xemacs-nox11
.  endif
.endif

_EMACS_VERSION_CMD!=	${PKG_INFO} -e "${_EMACS_PKGBASE}" || ${ECHO}
.if ${_EMACS_VERSION_CMD} != ""
_EMACS_VERSION_FULL=	${_EMACS_VERSION_CMD}
_EMACS_VERSION=		${_EMACS_VERSION_FULL:C/^${_EMACS_PKGBASE}-//}
_EMACS_VERSION_MAJOR=	${_EMACS_VERSION:C/\..*//}
_EMACS_VERSION_MINOR=	${_EMACS_VERSION:C/^[0-9]*\.//:C/[^0-9].*//}
_EMACS_VERSION_NOREV=	${_EMACS_VERSION:C/[a-z]*$//}
_EMACS_VERSION_ISMATCH!= \
	dep="${_EMACS_REQD.${_EMACS_TYPE}:Q}";				\
	${PKG_ADMIN} pmatch "$$dep" "${_EMACS_PKGBASE}";		\
	if [ $$? = 0 ]; then ${ECHO} "yes"; else ${ECHO} "no"; fi
.endif

EMACS_VERSIONS_ACCEPTED?=	${_EMACS_VERSIONS_ACCEPTED_DEFAULT}

.if empty(EMACS_VERSIONS_ACCEPTED:M${_EMACS_TYPE})
PKG_FAIL_REASON+=	"Accepted versions are: ${EMACS_VERSIONS_ACCEPTED}"
PKG_FAIL_REASON+=	"No valid Emacs version installed found"
.endif

#
# Dependencies and conflicts
#

DEPENDS+=	${_EMACS_REQD.${_EMACS_TYPE}}:${_EMACS_DEP.${_EMACS_TYPE}}
.if defined(EMACS_USE_LEIM)
.  if !empty(_EMACS_TYPE:Nxemacs*:Nemacs20*)
DEPENDS+=	${_EMACS_REQD.leim21}:${_EMACS_DEP.leim21}
.  else
DEPENDS+=	${_EMACS_REQD.leim20}:${_EMACS_DEP.leim20}
.  endif
.endif
.if !empty(_EMACS_TYPE:Nxemacs*)
CONFLICTS+=	xemacs-${PKGBASE}-[0-9]*
.else
CONFLICTS+=	${PKGBASE:C|^xemacs-||}-[0-9]*
.endif

#
# Macros for packages
#

EMACS_FLAVOR=		${_EMACS_TYPE:C|nox||:C|[0-9].*||}
EMACS_BIN=		${PREFIX}/bin/${EMACS_FLAVOR}
.if ${EMACS_FLAVOR} == "emacs"
EMACS_ETCPREFIX=	${PREFIX}/share
EMACS_INFOPREFIX=	${PREFIX}/info
EMACS_LISPPREFIX=	${PREFIX}/share/emacs/site-lisp
EMACS_PKGNAME_PREFIX=
.else
EMACS_ETCPREFIX=	${PREFIX}/lib/xemacs/site-packages/etc
EMACS_INFOPREFIX=	${PREFIX}/lib/xemacs/site-packages/info
EMACS_LISPPREFIX=	${PREFIX}/lib/xemacs/site-packages/lisp
EMACS_PKGNAME_PREFIX=	xemacs-
.endif

_EMACS_FOR.emacs=		"@comment "
_EMACS_FOR.emacs21=		"@comment "
_EMACS_FOR.emacs21nox=		"@comment "
_EMACS_FOR.emacs20=		"@comment "
_EMACS_FOR.xemacs=		"@comment "
_EMACS_FOR.xemacs215=		"@comment "
_EMACS_FOR.xemacs214=		"@comment "
_EMACS_NOTFOR.emacs=		""
_EMACS_NOTFOR.emacs21=		""
_EMACS_NOTFOR.emacs21nox=	""
_EMACS_NOTFOR.emacs20=		""
_EMACS_NOTFOR.xemacs=		""
_EMACS_NOTFOR.xemacs215=	""
_EMACS_NOTFOR.xemacs214=	""
_EMACS_FOR.${EMACS_FLAVOR}=	""
_EMACS_FOR.${_EMACS_TYPE}=	""
_EMACS_NOTFOR.${EMACS_FLAVOR}=	"@comment "
_EMACS_NOTFOR.${_EMACS_TYPE}=	"@comment "

PLIST_SUBST+=	EMACS_VERSION=${_EMACS_VERSION_NOREV:Q}
PLIST_SUBST+=	EMACS_LISPPREFIX=${EMACS_LISPPREFIX:C|^${PREFIX}/||}
PLIST_SUBST+=	FOR_emacs=${_EMACS_FOR.emacs}
PLIST_SUBST+=	FOR_emacs21=${_EMACS_FOR.emacs21}
PLIST_SUBST+=	FOR_emacs21nox=${_EMACS_FOR.emacs21nox}
PLIST_SUBST+=	FOR_emacs20=${_EMACS_FOR.emacs20}
PLIST_SUBST+=	FOR_xemacs=${_EMACS_FOR.xemacs}
PLIST_SUBST+=	FOR_xemacs215=${_EMACS_FOR.xemacs215}
PLIST_SUBST+=	FOR_xemacs214=${_EMACS_FOR.xemacs214}
PLIST_SUBST+=	NOTFOR_emacs=${_EMACS_NOTFOR.emacs}
PLIST_SUBST+=	NOTFOR_emacs21=${_EMACS_NOTFOR.emacs21}
PLIST_SUBST+=	NOTFOR_emacs21nox=${_EMACS_NOTFOR.emacs21nox}
PLIST_SUBST+=	NOTFOR_emacs20=${_EMACS_NOTFOR.emacs20}
PLIST_SUBST+=	NOTFOR_xemacs=${_EMACS_NOTFOR.xemacs}
PLIST_SUBST+=	NOTFOR_xemacs215=${_EMACS_NOTFOR.xemacs215}
PLIST_SUBST+=	NOTFOR_xemacs214=${_EMACS_NOTFOR.xemacs214}

.endif	# EMACS_MK
