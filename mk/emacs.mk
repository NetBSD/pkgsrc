# $NetBSD: emacs.mk,v 1.48 2008/01/18 13:50:44 obache Exp $
#
# This Makefile fragment handles Emacs Lisp Packages (== ELPs).
#
# Note to users:
#
#	* Users choose one favourite Emacs version (default GNU Emacs 21).
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
#			The user's favourite Emacs version.
#		Possible values:
#			emacs21, emacs21nox, emacs22, emacs22nox, emacs20, xemacs215, xemacs215nox, xemacs214, xemacs214nox
#		Default value:
#			emacs22
#
# Variables ELPs can provide:
#
#	EMACS_MODULES
#		Description:
#			List of Emacs LISP modules that the current ELP
#			needs at run-time.
#		Possible values:
#			base, leim
#		Default value:
#			<undefined>
#
#	EMACS_VERSIONS_ACCEPTED
#		Description:
#			Versions the ELP accepts (supports).
#		Possible values:
#			emacs21, emacs21nox, emacs22, emacs22nox, emacs20, xemacs215, xemacs215nox, xemacs214, xemacs214nox
#		Default value:
#			emacs21, emacs21nox, emacs22, emacs22nox, emacs20, xemacs215, xemacs215nox, xemacs214, xemacs214nox
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
#			${PREFIX}/${PKGINFODIR}
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
#	EMACS_VERSION_MAJOR
#		Description:
#			Emacs major version.
#		Possible values:
#			20, 21, 22, <integers more than that in the future>
#
#	EMACS_VERSION_MINOR
#		Description:
#			Emacs minor version.
#		Possible values:
#			<integer>
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
#			${PKGINFODIR}
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
#	FOR_{emacs,emacs21,emacs21nox,emacs22,emacs22nox,emacs20,xemacs,xemacs215,xemacs215nox,xemacs214,xemacs214nox}
#		Description:
#			These macros will become either an empty string or
#			"@comment" depending on the Emacs version; when
#			"emacs21" is used, ${FOR_emacs} and ${FOR_emacs21}
#			become "" (empty), and other macros become
#			"@comment"; this means that only the PLIST lines
#			prefixed by ${FOR_emacs} and ${FOR_emacs21} are
#			valid.
#		Possible values:
#			"", "@comment"
#
#	NOTFOR_{emacs,emacs21,emacs21nox,emacs22,emacs22nox,emacs20,xemacs,xemacs215,xemacs215nox,xemacs214,xemacs214nox}
#		Description:
#			The opposite of FOR_*.  See above.
#		Possible values:
#			"", "@comment"
#
#	FOR_emacs_{x,nox},NOTFOR_emacs_{x,nox}
#		Description:
#			PLIST switches for X11 / non-X11.
#		Possible values:
#			"", "@comment"
#

.if !defined(EMACS_MK)
EMACS_MK=	# defined

_VARGROUPS+=		emacs
_USER_VARS.emacs=	EMACS_TYPE
_PKG_VARS.emacs=	EMACS_MODULES EMACS_VERSIONS_ACCEPTED
_SYS_VARS.emacs=	EMACS_BIN EMACS_ETCPREFIX EMACS_FLAVOR \
			EMACS_INFOPREFIX EMACS_LISPPREFIX \
			EMACS_PKGNAME_PREFIX \
			EMACS_VERSION_MAJOR EMACS_VERSION_MINOR
_DEF_VARS.emacs=	_EMACS_TYPE _EMACS_PKGBASE _EMACS_VERSION_FULL _EMACS_BLNK
BUILD_DEFS+=		${_USER_VARS.emacs}
BUILD_DEFS_EFFECTS+=	${_SYS_VARS.emacs}

.include "../../mk/bsd.prefs.mk"

#
# Constants
#

_EMACS_VERSIONS_ALL= \
	emacs20 emacs21 emacs21nox emacs22 emacs22nox xemacs214 xemacs214nox xemacs215 xemacs215nox
_EMACS_VERSIONS_ACCEPTED_DEFAULT=	${_EMACS_VERSIONS_ALL}
_EMACS_VERSION_DEFAULT.emacs=	emacs21
_EMACS_VERSION_DEFAULT.xemacs=	xemacs214
_EMACS_REQD.emacs20=	emacs>=20.7<21
_EMACS_REQD.emacs21=	emacs>=21.2<22
_EMACS_REQD.emacs21nox=	emacs-nox11>=21.2<22
_EMACS_REQD.emacs22=	emacs>=22
_EMACS_REQD.emacs22nox=	emacs-nox11>=22
_EMACS_REQD.xemacs214=	xemacs>=21.4<21.5
_EMACS_REQD.xemacs214nox=	xemacs-nox11>=21.4<21.5
_EMACS_REQD.xemacs215=	xemacs>=21.5<21.6
_EMACS_REQD.xemacs215nox=	xemacs-nox11>=21.5<21.6
_LEIM_REQD.emacs20=	leim>=20.${EMACS_VERSION_MINOR}<21
_LEIM_REQD.emacs20nox=	${_LEIM_REQD.emacs20}
_LEIM_REQD.emacs21=	leim>=21.${EMACS_VERSION_MINOR}<22
_LEIM_REQD.emacs21nox=	${_LEIM_REQD.emacs21}
_LEIM_REQD.emacs22=	# nothing
_LEIM_REQD.emacs22nox=	${_LEIM_REQD.emacs22}
_EMACS_DEP.emacs20=	../../editors/emacs20
_EMACS_DEP.emacs21=	../../editors/emacs21
_EMACS_DEP.emacs21nox=	../../editors/emacs21-nox11
_EMACS_DEP.emacs22=	../../editors/emacs
_EMACS_DEP.emacs22nox=	../../editors/emacs-nox11
_EMACS_DEP.xemacs214=	../../editors/xemacs
_EMACS_DEP.xemacs214nox=../../editors/xemacs-nox11
_EMACS_DEP.xemacs215=	../../editors/xemacs-current
_EMACS_DEP.xemacs215nox=../../editors/xemacs-current-nox11
_LEIM_DEP.emacs20=	../../editors/leim20
_LEIM_DEP.emacs20nox=	${_LEIM_DEP.emacs20}
_LEIM_DEP.emacs21=	../../editors/leim21
_LEIM_DEP.emacs21nox=	${_LEIM_DEP.emacs21}
_LEIM_DEP.emacs22=
_LEIM_DEP.emacs20nox=	${_LEIM_DEP.emacs22}

_EMACS_BLNK.emacs20=	../../editors/emacs20/buildlink3.mk
_EMACS_BLNK.emacs21=	../../editors/emacs21/buildlink3.mk
_EMACS_BLNK.emacs21nox=	../../editors/emacs21-nox11/buildlink3.mk
_EMACS_BLNK.emacs22=	../../editors/emacs/buildlink3.mk
_EMACS_BLNK.emacs22nox=	../../editors/emacs-nox11/buildlink3.mk
_EMACS_BLNK.xemacs214=	../../editors/xemacs/buildlink3.mk
_EMACS_BLNK.xemacs214nox=	../../editors/xemacs-nox11/buildlink3.mk
_EMACS_BLNK.xemacs215=	../../editors/xemacs-current/buildlink3.mk
_EMACS_BLNK.xemacs215nox=	../../editors/xemacs-current-nox11/buildlink3.mk

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

.if ${EMACS_TYPE} == "emacs" || ${EMACS_TYPE} == "xemacs"
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
_EMACS_VERSION_NOREV=	${_EMACS_VERSION:C/[a-z].*$//}
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
EMACS_VERSION_MAJOR=	${_EMACS_VERSION_MAJOR}
EMACS_VERSION_MINOR=	${_EMACS_VERSION_MINOR}
.if ${EMACS_FLAVOR} == "emacs"
EMACS_ETCPREFIX=	${PREFIX}/share
EMACS_INFOPREFIX=	${PREFIX}/${PKGINFODIR}
EMACS_LISPPREFIX=	${PREFIX}/share/emacs/site-lisp
EMACS_PKGNAME_PREFIX=
.elif ${EMACS_FLAVOR} == "xemacs"
EMACS_ETCPREFIX=	${PREFIX}/lib/xemacs/site-packages/etc
EMACS_INFOPREFIX=	${PREFIX}/lib/xemacs/site-packages/info
EMACS_LISPPREFIX=	${PREFIX}/lib/xemacs/site-packages/lisp
EMACS_PKGNAME_PREFIX=	xemacs-
.else
PKG_FAIL_REASON+=	"\`\`${EMACS_FLAVOR}'' is not a valid EMACS_FLAVOR"
.endif
GNU_CONFIGURE_INFODIR?=	${EMACS_INFOPREFIX}

.for e in ${_EMACS_VERSIONS_ALL} emacs xemacs
.  if "${e}" == ${EMACS_FLAVOR} || "${e}" == ${_EMACS_TYPE}
PLIST_SUBST+=	FOR_${e}="" NOTFOR_${e}="@comment "
.  else
PLIST_SUBST+=	FOR_${e}="@comment " NOTFOR_${e}=""
.  endif
.endfor
.if empty(EMACS_TYPE:M*nox)
PLIST_SUBST+=	FOR_emacs_x="" NOTFOR_emacs_nox="@comment " FOR_emacs_nox="@comment " NOTFOR_emacs_nox="" 
.else
PLIST_SUBST+=	FOR_emacs_x="@comment " NOTFOR_emacs_nox="" FOR_emacs_nox="" NOTFOR_emacs_nox="@comment " 
.endif

PLIST_SUBST+=	EMACS_FLAVOR=${EMACS_FLAVOR:Q}
PLIST_SUBST+=	EMACS_VERSION=${_EMACS_VERSION_NOREV:Q}
PLIST_SUBST+=	EMACS_ETCPREFIX=${EMACS_ETCPREFIX:C|^${PREFIX}/||}
PLIST_SUBST+=	EMACS_INFOPREFIX=${EMACS_INFOPREFIX:C|^${PREFIX}/||}
PLIST_SUBST+=	EMACS_LISPPREFIX=${EMACS_LISPPREFIX:C|^${PREFIX}/||}

#
# ELP dependencies
#

EMACS_MODULES?=	# none

# "base" elisp modules
.if !empty(_EMACS_TYPE:Memacs*)
_EMACS_PKGDEP.${_EMACS_TYPE},base?=	# empty
.elif !empty(_EMACS_TYPE:Mxemacs*)
_EMACS_PKGDEP.${_EMACS_TYPE},base?=	\
		xemacs-packages>=1.15:../../editors/xemacs-packages
.endif

# "leim" - input methods for international character sets
_EMACS_PKGDEP.${_EMACS_TYPE},leim=	\
		${_LEIM_REQD.${_EMACS_TYPE}}:${_LEIM_DEP.${_EMACS_TYPE}}

.for _mod_ in ${EMACS_MODULES}
.if ${_EMACS_PKGDEP.${_EMACS_TYPE},${_mod_}} != ":"
DEPENDS+=	${_EMACS_PKGDEP.${_EMACS_TYPE},${_mod_}}
.endif
.endfor

#
# Build environment (buildlink3)
#

_EMACS_DIR=	${BUILDLINK_DIR}/share/emacs
ALL_ENV+=	EMACSLOADPATH=${_EMACS_DIR}/${_EMACS_VERSION_NOREV}/lisp:${_EMACS_DIR}/site-lisp

.include	"${_EMACS_BLNK.${_EMACS_TYPE}}"

.endif	# EMACS_MK
