# $NetBSD: modules.mk,v 1.26 2019/06/08 10:40:54 rillig Exp $
#
# This Makefile fragment handles Emacs Lisp Packages (== ELPs).
#
# Note to users:
#
#	* Users choose one favourite Emacs version.
#
#	* Emacs Lisp files are installed...
#		GNU emacs
#			-> ${PREFIX}/share/emacs/site-lisp/foo/...
#		XEmacs
#			->${PREFIX}/lib/xemacs/site-packages/lisp/foo/...
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
#			The user's favourite Emacs version.  The default
#			value is set in mk/defaults/mk.conf.
#		Possible values:
#			emacs26, emacs26nox, emacs25, emacs25nox, emacs21,
#			emacs21nox, emacs20, xemacs215, xemacs215nox,
#			xemacs214, xemacs214nox
#		Default value:
#			emacs26
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
#			emacs26, emacs26nox, emacs25, emacs25nox, emacs21,
#			emacs21nox, emacs20, xemacs215, xemacs215nox,
#			xemacs214, xemacs214nox
#		Default value:
#			emacs26, emacs26nox, emacs25, emacs25nox, emacs21,
#			emacs21nox, emacs20, xemacs215, xemacs215nox,
#			xemacs214, xemacs214nox
#
#	EMACS_BUILDLINK
#		Description:
#			Whether create buildlink directory of *.el / *.elc
#			files.  ELPs which include other ELP's buildlink3.mk
#			must define this value.
#		Possible values:
#			<defined>, <undefined>
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
#			${PREFIX}/lib/xemacs/site-packages/etc
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
#			${PREFIX}/lib/xemacs/site-packages/info
#
#	EMACS_LISPPREFIX
#		Description:
#			installed into.  ELPs should append a short name
#			as a subdirectory.
#		Possible values:
#			${PREFIX}/share/emacs/site-lisp
#			${PREFIX}/lib/xemacs/site-packages/lisp
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
#			20, 21, 25, 26, <integers more than that in the future>
#
#	EMACS_VERSION_MINOR
#		Description:
#			Emacs minor version.
#		Possible values:
#			<integer>
#
#	EMACS_VERSION_MICRO
#		Description:
#			Emacs micro version.
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
#			lib/xemacs/site-packages/etc
#
#	EMACS_INFOPREFIX
#		Description:
#			Same as the one in Makefile, except that
#			${PREFIX} is omitted in PLIST.
#		Possible values:
#			${PKGINFODIR}
#			lib/xemacs/site-packages/info
#
#	EMACS_LISPPREFIX
#		Description:
#			Same as the one in Makefile, except that
#			${PREFIX} is omitted in PLIST.
#		Possible values:
#			share/emacs/site-lisp
#			lib/xemacs/site-packages/lisp
#
#	EMACS_VERSION
#		Description:
#			XXX
#		Possible values:
#			XXX
#
#	FOR_{emacs26,emacs26nox,emacs25,emacs25nox,emacs21,emacs21nox,emacs20,xemacs215,xemacs215nox,xemacs214,xemacs214nox}
#	FOR_{emacs,xemacs}
#	FOR_{emacs_x,emacs_nox}
#	NOTFOR_{emacs26,eemacs26nox,macs25,emacs25nox,emacs21,emacs21nox,emacs20,xemacs215,xemacs215nox,xemacs214,xemacs214nox}
#	NOTFOR_{emacs,xemacs}
#	NOTFOR_{emacs_x,emacs_nox}
#		Description:
#			These macros will become either an empty string or
#			"@comment" depending on the Emacs version; when
#			"emacs21" is used, ${FOR_emacs} and ${FOR_emacs21}
#			become "" (empty), and other macros become
#			"@comment"; this means that only the PLIST lines
#			prefixed by ${FOR_emacs} and ${FOR_emacs21} are
#			valid.
#
#			NOTFOR_* is the opposite of FOR_*.
#		Possible values:
#			"", "@comment"
#
#	FOR_emacs_no_byte_compile
#		Description:
#			For .elc file of .el file marked as "no-byte-compile: t"
#		Possible values:
#			"", "@comment"

.if !defined(EMACS_MK)
EMACS_MK=	# defined

_VARGROUPS+=		emacs
_USER_VARS.emacs=	EMACS_TYPE
_PKG_VARS.emacs=	EMACS_MODULES EMACS_VERSIONS_ACCEPTED
_SYS_VARS.emacs=	EMACS_BIN EMACS_ETCPREFIX EMACS_FLAVOR \
			EMACS_INFOPREFIX EMACS_LISPPREFIX \
			EMACS_PKGNAME_PREFIX \
			EMACS_VERSION_MAJOR EMACS_VERSION_MINOR \
			EMACS_VERSION_MICRO
_DEF_VARS.emacs=	_EMACS_TYPE _EMACS_PKGBASE
_SORTED_VARS.emacs=	*_MODULES
_LISTED_VARS.emacs=	*VERSIONS*

BUILD_DEFS+=		${_USER_VARS.emacs}
BUILD_DEFS_EFFECTS+=	${_SYS_VARS.emacs}

.include "../../mk/bsd.prefs.mk"

#
# Constants
#

_EMACS_VERSIONS_ALL= \
	emacs20 emacs21 emacs21nox emacs25 emacs25nox emacs26 emacs26nox\
	xemacs214 xemacs214nox xemacs215 xemacs215nox

_EMACS_PKGDIR_MAP= \
	emacs20@../../editors/emacs20 \
	emacs21@../../editors/emacs21 \
	emacs21nox@../../editors/emacs21-nox11 \
	emacs25@../../editors/emacs25 \
	emacs25nox@../../editors/emacs25-nox11 \
	emacs26@../../editors/emacs26 \
	emacs26nox@../../editors/emacs26-nox11 \
	xemacs214@../../editors/xemacs \
	xemacs214nox@../../editors/xemacs-nox11 \
	xemacs215@../../editors/xemacs-current \
	xemacs215nox@../../editors/xemacs-current-nox11

_EMACS_ETCDIR.emacs=		share
_EMACS_INFODIR.emacs=		${PKGINFODIR}
_EMACS_LISPDIR.emacs=		share/emacs/site-lisp
_EMACS_PKGNAME_PREFIX.emacs=
_EMACS_CONFLICTS.emacs=		xemacs-${PKGBASE}-[0-9]*

_EMACS_ETCDIR.xemacs=		lib/xemacs/site-packages/etc
_EMACS_INFODIR.xemacs=		lib/xemacs/site-packages/info
_EMACS_LISPDIR.xemacs=		lib/xemacs/site-packages/lisp
_EMACS_PKGNAME_PREFIX.xemacs=	xemacs-
_EMACS_CONFLICTS.xemacs=	${PKGBASE:C|^xemacs-||}-[0-9]*

#
# Version decision
#
# 1. Pick up an emacs version.
#
#	add a dependency to the version;
#
# 2. Check if a given package can be used for the emacs version.
#
# 	if (package accepts the emacs version)
#		nothing to do;
#	else
#		abort;
#

_EMACS_TYPE=	${EMACS_TYPE}

EMACS_VERSIONS_ACCEPTED?=	${_EMACS_VERSIONS_ALL}
.if empty(EMACS_VERSIONS_ACCEPTED:M${_EMACS_TYPE})
PKG_FAIL_REASON+=		"Accepted versions are: ${EMACS_VERSIONS_ACCEPTED}"
PKG_FAIL_REASON+=		"No valid Emacs version installed found"
.endif

_EMACS_PKGDIR=	${_EMACS_PKGDIR_MAP:M${_EMACS_TYPE}@*:C|${_EMACS_TYPE}@||}

.include "${_EMACS_PKGDIR}/version.mk"

#
# Dependencies and conflicts
#

DEPENDS+=	${_EMACS_REQD}:${_EMACS_PKGDIR}
CONFLICTS+=	${_EMACS_CONFLICTS.${_EMACS_FLAVOR}}

EMACS_MODULES?=
.for _mod_ in ${EMACS_MODULES}
.  if !empty(_EMACS_PKGDEP.${_mod_})
DEPENDS+=	${_EMACS_PKGDEP.${_mod_}}
.  endif
.endfor

#
# Macros for packages
#

EMACS_FLAVOR=		${_EMACS_FLAVOR}
EMACS_BIN=		${PREFIX}/bin/${_EMACS_FLAVOR}
EMACS_VERSION_MAJOR=	${_EMACS_VERSION_MAJOR}
EMACS_VERSION_MINOR=	${_EMACS_VERSION_MINOR}
EMACS_VERSION_MICRO=	${_EMACS_VERSION_MICRO}
EMACS_ETCPREFIX=	${PREFIX}/${_EMACS_ETCDIR.${_EMACS_FLAVOR}}
EMACS_INFOPREFIX=	${PREFIX}/${_EMACS_INFODIR.${_EMACS_FLAVOR}}
EMACS_LISPPREFIX=	${PREFIX}/${_EMACS_LISPDIR.${_EMACS_FLAVOR}}
EMACS_PKGNAME_PREFIX=	${_EMACS_PKGNAME_PREFIX.${_EMACS_FLAVOR}}

GNU_CONFIGURE_INFODIR?=	${EMACS_INFOPREFIX}

_EMACS_PLIST_SUBST=
.for e in ${_EMACS_VERSIONS_ALL} emacs xemacs
.  if "${e}" == ${EMACS_FLAVOR} || "${e}" == ${_EMACS_TYPE}
_EMACS_PLIST_SUBST+=	FOR_${e}="" NOTFOR_${e}="@comment "
.  else
_EMACS_PLIST_SUBST+=	FOR_${e}="@comment " NOTFOR_${e}=""
.  endif
.endfor
.if empty(EMACS_TYPE:M*nox)
_EMACS_PLIST_SUBST+=	FOR_emacs_x="" NOTFOR_emacs_x="@comment "
_EMACS_PLIST_SUBST+=	FOR_emacs_nox="@comment " NOTFOR_emacs_nox=""
.else
_EMACS_PLIST_SUBST+=	FOR_emacs_x="@comment " NOTFOR_emacs_x=""
_EMACS_PLIST_SUBST+=	FOR_emacs_nox="" NOTFOR_emacs_nox="@comment "
.endif

_EMACS_PLIST_SUBST+=	EMACS_FLAVOR=${EMACS_FLAVOR:Q}
_EMACS_PLIST_SUBST+=	EMACS_VERSION=${_EMACS_VERSION_MAJOR:Q}.${_EMACS_VERSION_MINOR:Q}
_EMACS_PLIST_SUBST+=	EMACS_ETCPREFIX=${EMACS_ETCPREFIX:C|^${PREFIX}/||}
_EMACS_PLIST_SUBST+=	EMACS_INFOPREFIX=${EMACS_INFOPREFIX:C|^${PREFIX}/||}
_EMACS_PLIST_SUBST+=	EMACS_LISPPREFIX=${EMACS_LISPPREFIX:C|^${PREFIX}/||}

_EMACS_PLIST_SUBST+=	FOR_emacs_no_byte_compile="${${EMACS_VERSION_MAJOR}>22:?@comment :}"

PLIST_SUBST+=		${_EMACS_PLIST_SUBST}

PRINT_PLIST_AWK+=	{ gsub(/${EMACS_LISPPREFIX:S|${PREFIX}/||:S|/|\\/|g}/, \
			"$${EMACS_LISPPREFIX}"); \
			print; next; }

#
# Build environment (buildlink3)
#

.if defined(EMACS_BUILDLINK)
_EMACS_DIR=	${BUILDLINK_DIR}/share/emacs
#  development version usually claims three digit, say, 27.0.50 etc
.  if ${EMACS_TYPE} == emacs27
ALL_ENV+=	EMACSLOADPATH=${_EMACS_DIR}/${_EMACS_VERSION_MAJOR}.${_EMACS_VERSION_MINOR}.${_EMACS_VERSION_MICRO}/lisp:${_EMACS_DIR}/site-lisp
.  else
ALL_ENV+=	EMACSLOADPATH=${_EMACS_DIR}/${_EMACS_VERSION_MAJOR}.${_EMACS_VERSION_MINOR}/lisp:${_EMACS_DIR}/site-lisp
.  endif
.include	"${_EMACS_PKGDIR}/buildlink3.mk"
.endif

.endif	# EMACS_MK
