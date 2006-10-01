# $NetBSD: tex.buildlink3.mk,v 1.17 2006/10/01 14:53:30 rillig Exp $
#
# This file is included by packages that need a TeX package to work.
#
# The following variables may be set by the pkgsrc user in mk.conf:
#
# TEX_DEFAULT
#	The user's favorite TeX implementation.
#
#	Possible values: teTeX3
#	Default value: teTeX3
#
# The following variables may be set by a package:
#
# TEX_DEPMETHOD
#	Select whether TeX is a runtime dependency or only needed
#	when building the package.
#
#	Possible values: build run
#	Default value: run
#
# TEX_ACCEPTED
#	List of TeX implementations that the package supports.
#
#	Possible values: teTeX3
#	Default value: teTeX3
#
# After including this file, the following variables may be used, but not
# in directives like .if, .for, etc.
#
# PKG_TEXMFPREFIX
#	Absolute pathname of the directory where the standard TeX files
#	can be found.
#
#	Typical values: ${PREFIX}/share/texmf ${PREFIX}/share/texmf-dist
#
# PKG_LOCALTEXMFPREFIX
#	Absolute pathname of the directory where extensions for TeX can
#	be found.
#
#	Typical values: ${PREFIX}/share/texmf ${PREFIX}/share/texmf-local
#
# TEX_TYPE
#	The TeX implementation that has been selected based on the
#	package's and the user's preferences.
#
#	Typical values: teTeX3
#

# NOTE: before all TeX-related packages are converted to use these
# variables, we will keep PKG_TEXMFPREFIX = PKG_LOCALTEXMFPREFIX =
# ${PREFIX}/share/texmf

.if !defined(TEX_BUILDLINK3_MK)
TEX_BUILDLINK3_MK=	# defined

.include "../../mk/bsd.prefs.mk"

TEX_DEPMETHOD?= run

# Assume only teTeX 3 is supported by default.
TEX_ACCEPTED?=	teTeX3

# set up variables for buildlink or depends
#
BUILDLINK_API_DEPENDS.teTeX3=	teTeX-bin-3.[0-9]*
BUILDLINK_PKGSRCDIR.teTeX3=	../../print/teTeX3-bin

# Determine the TeX version to be used.
#
.if !defined(_TEX_TYPE)
_TEX_TYPE=	${TEX_DEFAULT}
.endif

.if !empty(TEX_ACCEPTED:M${_TEX_TYPE})
TEX_TYPE=	${_TEX_TYPE}
.else
TEX_TYPE=	none
.endif

# Set version specifics.
#
.if ${TEX_TYPE} == "teTeX3"
_TEX_DEPENDENCY=	${BUILDLINK_API_DEPENDS.teTeX3}
_TEX_PKGSRCDIR=	${BUILDLINK_PKGSRCDIR.teTeX3}
.endif

.endif	# TEX_BUILDLINK3_MK

.if ${TEX_TYPE} == "none"
PKG_FAIL_REASON=	\
	"${_TEX_TYPE} is not an acceptable (${TEX_ACCEPTED})\
	    TeX version for ${PKGNAME}."
.else
PLIST_SUBST+=	TEX_TYPE=${TEX_TYPE:Q}
.if (${TEX_DEPMETHOD} == "build")
BUILD_DEPENDS+=	${_TEX_DEPENDENCY}:${_TEX_PKGSRCDIR}
.else
TEX_DEPMETHOD:= run
.  include "${_TEX_PKGSRCDIR}/buildlink3.mk"

.endif
.endif
