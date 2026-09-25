# $NetBSD: modules.mk,v 1.43 2026/09/25 09:46:51 wiz Exp $
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
#	* You can't necessarily install an ELP for both Emacs and XEmacs
#	  simultaneously, though because of the above path difference many
#	  do not conflict with one another.
#
#	* XEmacs packages' names are prefixed by "xemacs-".
#
# Note to package developers:
#
#	* XEmacs packages' names are prefixed by "xemacs-".
#
#	  This is to make sure ELPs for XEmacs keep their own dependency
#	  tree. For example, if an ELP "bar" depends on another ELP "foo",
#	  "xemacs-bar" depends on "xemacs-foo".  "foo" (installed for GNU
#	  Emacs) is useless for "xemacs-bar" in this case.
#
#	  Make sure too that "foo" and "xemacs-foo" conflict each other,
#	  since they can share some files.  (Making all ELPs separately
#	  installable for GNU Emacs/XEmacs might be possible.)
#
#	* Assume each ELP supports all Emacs versions by default.  If the
#	  ELP supports only certain Emacs versions, define EMACS_VERSIONS
#	  _ACCEPTED explicitly before including emacs/modules.mk.
#
# Variables for users:
#
#	EMACS_TYPE
#		Description:
#			The user's favourite Emacs version.  The default
#			value is set in mk/defaults/mk.conf.
#		Possible values:
#			emacs31 emacs31nox
#			emacs30 emacs30nox
#			emacs29 emacs29nox
#			emacs20 xemacs215 xemacs215nox
#			xemacs214 xemacs214nox
#		Default value:
#			emacs29
#
# Variables ELPs can provide:
#
#	EMACS_MODULES
#		Description:
#			List of Emacs LISP modules that the current ELP
#			needs at run-time.
#		Possible values:
#			base leim
#		Default value:
#			<undefined>
#
#	EMACS_VERSIONS_ACCEPTED
#		Description:
#			Versions the ELP accepts (supports).
#
#			Naming emacs30 accepts emacs30nox as well: they are
#			one Emacs built two ways, and no package in the tree
#			installs a different file list for the two.  To allow
#			only one of the two versions, name the other one in
#			EMACS_VERSIONS_INCOMPATIBLE.
#		Possible values:
#			emacs31 emacs30 emacs29 emacs20
#			xemacs215 xemacs214
#		Default value:
#			emacs31 emacs31nox
#			emacs30 emacs30nox
#			emacs29 emacs29nox
#			emacs20
#			xemacs215 xemacs214
#
#	EMACS_VERSIONS_INCOMPATIBLE
#		Description:
#			Versions the ELP does not work with, removed
#			from EMACS_VERSIONS_ACCEPTED.
#		Possible values:
#			any of the values from EMACS_VERSIONS_ACCEPTED
#			
#		Default value:
#			empty
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
#			EMACS_LISPPREFIX, a subdirectory is not needed.
#			For GNU Emacs this is PKGINFODIR, which this file
#			sets to the version directory when PKGNAME carries
#			EMACS_PKGNAME_PREFIX, so a PLIST may use either
#			${EMACS_INFOPREFIX}/ or info/.
#		Possible values:
#			${PREFIX}/${PKGINFODIR}
#			${PREFIX}/lib/xemacs/site-packages/info
#
#	EMACS_LISPPREFIX
#		Description:
#			installed into.  ELPs should append a short name
#			as a subdirectory.
#		Possible values:
#			${PREFIX}/share/emacs/${EMACS_VERSION_MAJOR}.${EMACS_VERSION_MINOR}/site-lisp
#			${PREFIX}/lib/xemacs/site-packages/lisp
#
#	EMACS_PKGNAME_PREFIX
#		Description:
#			The prefix of PKGNAME and DEPENDS lines.  All ELPs
#			must honor this!
#
#			It carries the version, not the flavor, so that one
#			bulk build can make the same package for every Emacs
#			and the name says which one it was made for.  The two
#			builds of one Emacs share it: emacs30 and
#			emacs30-nox11 conflict with each other and install
#			their lisp files in the same directory, so emacs30-foo
#			serves either.  A package that refuses one of the two
#			(using EMACS_VERSIONS_INCOMPATIBLE) gets the longer name.
#		Possible values:
#			"emacs20-", "emacs29-", "emacs30-", "emacs31-",
#			"xemacs214-", "xemacs215-"
#			and, for a package that takes only the nox build,
#			"emacs30-nox11-" and so on
#
#	EMACS_VERSION_MAJOR
#		Description:
#			Emacs major version.
#		Possible values:
#			20, 29, 30, 31, <integers more than that in the future>
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
#	EMACS_PKGNAME_PREFIX
#		Description:
#			See above.
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
#			share/emacs/${EMACS_VERSION_MAJOR}.${EMACS_VERSION_MINOR}/site-lisp
#			lib/xemacs/site-packages/lisp
#
#	EMACS_VERSION
#		Description:
#			XXX
#		Possible values:
#			XXX
#
#	FOR_{emacs31,emacs31nox,emacs30,emacs30nox,emacs29,emacs29nox,emacs20,xemacs215,xemacs215nox,xemacs214,xemacs214nox}
#	FOR_{emacs,xemacs}
#	NOTFOR_{emacs31,emacs31nox,emacs30, emacs30nox,emacs29,emacs29nox,emacs20,xemacs215,xemacs215nox,xemacs214,xemacs214nox}
#	NOTFOR_{emacs,xemacs}
#		Description:
#			These macros will become either an empty string or
#			"@comment" depending on the Emacs version; when
#			"emacs20" is used, ${FOR_emacs} and ${FOR_emacs20}
#			become "" (empty), and other macros become
#			"@comment"; this means that only the PLIST lines
#			prefixed by ${FOR_emacs} and ${FOR_emacs20} are
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

# Newest first.  A package that does not specify versions itself gets
# this list as EMACS_VERSIONS_ACCEPTED, so the order here is the
# default preference; where a package does name its own, that list's
# order is what counts.
_EMACS_VERSIONS_ALL= \
	emacs31 emacs31nox emacs30 emacs30nox \
	emacs29 emacs29nox emacs20 \
	xemacs215 xemacs215nox xemacs214 xemacs214nox

_EMACS_PKGDIR_MAP= \
	emacs20@../../editors/emacs20 \
	emacs29@../../editors/emacs29 \
	emacs29nox@../../editors/emacs29-nox11 \
	emacs30@../../editors/emacs30 \
	emacs30nox@../../editors/emacs30-nox11 \
	emacs31@../../editors/emacs31 \
	emacs31nox@../../editors/emacs31-nox11 \
	xemacs214@../../editors/xemacs \
	xemacs214nox@../../editors/xemacs-nox11 \
	xemacs215@../../editors/xemacs-current \
	xemacs215nox@../../editors/xemacs-current-nox11

# Data installed beside the lisp moves with it.
_EMACS_ETCDIR.emacs=		share/emacs/${_EMACS_VERSION_MAJOR}.${_EMACS_VERSION_MINOR}/etc
# Info goes under the version too, to avoid conflicts between emacs*-foo packages,
# if we ever allow parallel installation of different emacs versions.
# Use the pkgsrc PKGINFODIR handling (setting this variable, see below)
# so the PLIST magic for info/foo.info works.
_EMACS_INFODIR.emacs=		${PKGINFODIR}
# Put the lisp under the version directory of the Emacs it was built
# for.  Emacs already searches share/emacs/<version>/site-lisp, so what
# lands there is seen by that Emacs and by no other.
_EMACS_LISPDIR.emacs=		share/emacs/${_EMACS_VERSION_MAJOR}.${_EMACS_VERSION_MINOR}/site-lisp
_EMACS_PKGNAME_PREFIX.emacs=

_EMACS_ETCDIR.xemacs=		lib/xemacs/site-packages/etc
_EMACS_INFODIR.xemacs=		lib/xemacs/site-packages/info
_EMACS_LISPDIR.xemacs=		lib/xemacs/site-packages/lisp
_EMACS_PKGNAME_PREFIX.xemacs=	xemacs-

#
# Version decision
#
# 1. Pick up an Emacs version.
#
#	add a dependency to the version;
#
# 2. Check if a given package can be used for the Emacs version.
#
# 	if (package accepts the Emacs version)
#		nothing to do;
#	else
#		abort;
#

EMACS_VERSIONS_ACCEPTED?=	${_EMACS_VERSIONS_ALL}

# The Emacs this machine uses when the package does not care.  EMACS_TYPE
# is the name this has always had; keep honoring it.
EMACS_VERSION_DEFAULT?=		${EMACS_TYPE}

# Which Emacs to build for.
#
#   - EMACS_VERSION_REQD names one version.  Use it, and refuse if the
#     package does not accept it, so a bulk build walking the set leaves
#     the package alone in that pass rather than building it for some
#     other version.
#   - otherwise EMACS_VERSION_DEFAULT, if the package accepts it.
#   - otherwise the first version the package accepts, reading its list
#     in the order it was written.  Like PYTHON_VERSIONS_ACCEPTED the
#     order is the package's preference, so the list is written newest
#     first.
#
# The versions this package accepts that pkgsrc still has, in the order
# the package wrote them: the order is the package's preference and is
# meant to be honored.
EMACS_VERSIONS_INCOMPATIBLE?=	# empty

_EMACS_VERSIONS_OK=	# empty
# Naming emacs30 accepts the nox build of it as well, so a package does
# not have to write both halves of every pair.  Writing emacs30nox on its
# own still works.  A package that takes only one of the two names the
# other in EMACS_VERSIONS_INCOMPATIBLE.
.for _ev_ in ${EMACS_VERSIONS_ACCEPTED}
.  for _cand_ in ${_ev_} ${_ev_}nox
.    if !empty(_EMACS_VERSIONS_ALL:M${_cand_}) && \
        empty(EMACS_VERSIONS_INCOMPATIBLE:M${_cand_}) && \
        empty(_EMACS_VERSIONS_OK:M${_cand_})
_EMACS_VERSIONS_OK+=	${_cand_}
.    endif
.  endfor
.endfor

# What a bulk build should build: one entry per name.  Where both builds
# of one Emacs are accepted they produce the same package, so only the
# plain one is listed; where only the nox build is accepted it stays,
# because then it is the only way to get that package at all.
_EMACS_VERSIONS_BULK=	# empty
.for _ev_ in ${_EMACS_VERSIONS_OK}
_EMACS_BULK_CAND=	${_ev_}
.  if empty(_EMACS_BULK_CAND:M*nox) || \
      empty(_EMACS_VERSIONS_OK:M${_EMACS_BULK_CAND:C/nox$//})
_EMACS_VERSIONS_BULK+=	${_ev_}
.  endif
.endfor

# The bulk index wants its default to be one of the entries it lists, and
# the entries are the folded names, so the default folds the same way.
.if !empty(EMACS_VERSION_DEFAULT:M*nox) && \
    !empty(_EMACS_VERSIONS_BULK:M${EMACS_VERSION_DEFAULT:C/nox$//})
_EMACS_VERSION_BULK_DEFAULT=	${EMACS_VERSION_DEFAULT:C/nox$//}
.else
_EMACS_VERSION_BULK_DEFAULT=	${EMACS_VERSION_DEFAULT}
.endif

# When pkgsrc resolves a dependency it passes the pattern it is looking
# for as PKGNAME_REQD (mk/pkgformat/pkg/depends.mk).  Once the version is
# part of the name, that pattern says which Emacs the package asking for
# it settled on, and the dependency has to be built for the same one.
.if defined(PKGNAME_REQD)
.  for _ev_ in ${_EMACS_VERSIONS_ALL}
.    if !empty(PKGNAME_REQD:M${_ev_}-*)
EMACS_VERSION_REQD?=	${_ev_}
.    endif
.  endfor
.endif

.if defined(EMACS_VERSION_REQD) && !empty(EMACS_VERSION_REQD)
.  if !empty(_EMACS_VERSIONS_OK:M${EMACS_VERSION_REQD})
_EMACS_TYPE=		${EMACS_VERSION_REQD}
.  else
# The version asked for cannot be used.  Refuse, but leave _EMACS_TYPE
# at a version that exists: _EMACS_PKGDIR is looked up from it a few
# lines below, and an empty one turns this clean refusal into "Cannot
# open /version.mk", a fatal error that stops the whole make instead of
# failing the one package.
_EMACS_TYPE=		${_EMACS_VERSIONS_ALL:[1]}
# Two different things send us here, and a bulk build wants to tell them
# apart: the package will not take that Emacs, or pkgsrc no longer has
# it at all.
.    if empty(_EMACS_VERSIONS_ALL:M${EMACS_VERSION_REQD})
PKG_FAIL_REASON+=	"pkgsrc no longer has ${EMACS_VERSION_REQD}"
PKG_FAIL_REASON+=	"pkgsrc has: ${_EMACS_VERSIONS_ALL}"
.    else
PKG_FAIL_REASON+=	"This package does not build with ${EMACS_VERSION_REQD}"
PKG_FAIL_REASON+=	"Accepted versions are: ${EMACS_VERSIONS_ACCEPTED}"
.    endif
.  endif
.elif !empty(_EMACS_VERSIONS_OK:M${EMACS_VERSION_DEFAULT})
_EMACS_TYPE=		${EMACS_VERSION_DEFAULT}
.elif !empty(_EMACS_VERSIONS_OK)
_EMACS_TYPE=		${_EMACS_VERSIONS_OK:[1]}
.else
# Everything the package asks for has been removed from pkgsrc.  Say so,
# and pick a version that exists so that the includes below still have a
# directory to read; the package is failing anyway.
_EMACS_TYPE=		${_EMACS_VERSIONS_ALL:[1]}
PKG_FAIL_REASON+=	"No Emacs that pkgsrc still has is accepted here"
PKG_FAIL_REASON+=	"Accepted versions are: ${EMACS_VERSIONS_ACCEPTED}"
PKG_FAIL_REASON+=	"pkgsrc has: ${_EMACS_VERSIONS_ALL}"
.endif

_EMACS_PKGDIR=	${_EMACS_PKGDIR_MAP:M${_EMACS_TYPE}@*:C|${_EMACS_TYPE}@||}

.include "${_EMACS_PKGDIR}/version.mk"

# Put info files in a version-specific directory to avoid
# conflicts between e.g. emacs29-foo and emacs30-foo.
#
# Unlike the lisp, Emacs does not find info under its version
# directory by itself: Info-default-directory-list is built from the
# Emacs's own --infodir at configure time, and the only runtime lever
# is INFOPATH.  For this reason, the Emacs packages install a
# site-start.el beside their site-lisp that adds ../info to the list.
.if ${_EMACS_FLAVOR} == "emacs"
_EMACS_PKGINFODIR_DEFAULT:=	${PKGINFODIR}
PKGINFODIR=	${"${PKGNAME:M${EMACS_PKGNAME_PREFIX}*}" != "":?share/emacs/${_EMACS_VERSION_MAJOR}.${_EMACS_VERSION_MINOR}/info:${_EMACS_PKGINFODIR_DEFAULT}}
.endif

#
# Dependencies and conflicts
#

# One binary package serves both builds of an Emacs, so either version
# is good enough.
#
# A package that genuinely needs one of the two refuses the other in
# EMACS_VERSIONS_INCOMPATIBLE.
.if !empty(_EMACS_TYPE:M*nox)
_EMACS_TYPE_OTHER=	${_EMACS_TYPE:C/nox$//}
_EMACS_REQD_OTHER=	${_EMACS_REQD:C/[<>=].*//:C/-nox11$//}
.else
_EMACS_TYPE_OTHER=	${_EMACS_TYPE}nox
_EMACS_REQD_OTHER=	${_EMACS_REQD:C/[<>=].*//}-nox11
.endif

DEPENDS+=	${_EMACS_REQD}:${_EMACS_PKGDIR}

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
# Build with the versioned Emacs binary the package is being built for.
_EMACS_BIN_NAME.emacs=	emacs-${_EMACS_VERSION_MAJOR}.${_EMACS_VERSION_MINOR}
_EMACS_BIN_NAME.xemacs=	xemacs
_EMACS_BIN_NAME?=	${_EMACS_BIN_NAME.${_EMACS_FLAVOR}}
EMACS_BIN=		${PREFIX}/bin/${_EMACS_BIN_NAME}
EMACS_VERSION_MAJOR=	${_EMACS_VERSION_MAJOR}
EMACS_VERSION_MINOR=	${_EMACS_VERSION_MINOR}
EMACS_VERSION_MICRO=	${_EMACS_VERSION_MICRO}
EMACS_ETCPREFIX=	${PREFIX}/${_EMACS_ETCDIR.${_EMACS_FLAVOR}}
EMACS_INFOPREFIX=	${PREFIX}/${_EMACS_INFODIR.${_EMACS_FLAVOR}}
EMACS_LISPPREFIX=	${PREFIX}/${_EMACS_LISPDIR.${_EMACS_FLAVOR}}
# Which Emacs a package was built for is part of the name.
#
# The nox build and the X build of one Emacs conflict with each other and
# share a lisp directory, and no package in the tree installs a different
# file list for the two, so by default they do not get different names:
# one emacs30-foo serves either, and a bulk build makes one of it rather
# than two.
#
# The exception earns the longer name.  A package that refuses the X
# build -- it says so in EMACS_VERSIONS_INCOMPATIBLE -- is not the same
# thing as the ordinary one, so it is called emacs30-nox11-foo, after the
# Emacs it needs.  A package that refuses the nox build keeps the plain
# name, because there is no other emacs30-foo for it to be confused with.
.if !empty(_EMACS_TYPE:M*nox) && empty(_EMACS_VERSIONS_OK:M${_EMACS_TYPE:C/nox$//})
EMACS_PKGNAME_PREFIX=	${_EMACS_TYPE:C/nox$/-nox11/}-
.else
EMACS_PKGNAME_PREFIX=	${_EMACS_TYPE:C/nox$//}-
.endif

_EMACS_PLIST_SUBST=
.for e in ${_EMACS_VERSIONS_ALL} emacs xemacs
.  if "${e}" == ${EMACS_FLAVOR} || "${e}" == ${_EMACS_TYPE}
_EMACS_PLIST_SUBST+=	FOR_${e}="" NOTFOR_${e}="@comment "
.  else
_EMACS_PLIST_SUBST+=	FOR_${e}="@comment " NOTFOR_${e}=""
.  endif
.endfor

_EMACS_PLIST_SUBST+=	EMACS_FLAVOR=${EMACS_FLAVOR:Q}
_EMACS_PLIST_SUBST+=	EMACS_VERSION=${_EMACS_VERSION_MAJOR:Q}.${_EMACS_VERSION_MINOR:Q}
_EMACS_PLIST_SUBST+=	EMACS_ETCPREFIX=${EMACS_ETCPREFIX:C|^${PREFIX}/||}
_EMACS_PLIST_SUBST+=	EMACS_INFOPREFIX=${EMACS_INFOPREFIX:C|^${PREFIX}/||}
_EMACS_PLIST_SUBST+=	EMACS_LISPPREFIX=${EMACS_LISPPREFIX:C|^${PREFIX}/||}
_EMACS_PLIST_SUBST+=	EMACS_PKGNAME_PREFIX=${EMACS_PKGNAME_PREFIX:Q}

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
# A development version usually claims three digits, say, 27.0.50 etc.
# The lisp of other packages now lives under the version directory, so
# the build-time load path has to name it too; ${_EMACS_DIR}/site-lisp
# alone finds nothing and the byte-compile fails with "Cannot open load
# file".  The shared directory stays last for anything still installed
# there.
ALL_ENV+=	EMACSLOADPATH=${_EMACS_DIR}/${_EMACS_VERSION_MAJOR}.${_EMACS_VERSION_MINOR}/lisp:${_EMACS_DIR}/${_EMACS_VERSION_MAJOR}.${_EMACS_VERSION_MINOR}/site-lisp:${_EMACS_DIR}/site-lisp
.include	"${_EMACS_PKGDIR}/buildlink3.mk"
.endif

.endif	# EMACS_MK
