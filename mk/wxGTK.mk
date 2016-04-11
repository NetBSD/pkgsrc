# $NetBSD: wxGTK.mk,v 1.2 2016/04/11 04:22:34 dbj Exp $
#
# This Makefile fragment is meant to be included by packages that
# require a wxGTK library.  wxGTK.mk will:
#
#	* set WXGTKBASE to the directory of wxGTK package
#	* set WXGTK_TYPE to the version of wxGTK used.
#
# Because multiple versions of wxGTK cannot currently coexist, the
# strategy is to use a single version, with each package building with
# it if possible and failing otherwise.
#
# There are two variables that can be used to influence the selection of
# the version of wxGTK.
#
# WXGTK_DEFAULT is a user-settable variable whose value is the default
#	version of wxGTK, for example WXGTK28 or WXGTK30.
#
# WXGTK_ACCEPTED is a package-settable list of wxGTK versions
#	that may be used by the package.
#

MK_WXGTK_BUILDLINK3_MK:=	${MK_WXGTK_BUILDLINK3_MK}+

.include "../../mk/bsd.fast.prefs.mk"

.if !empty(MK_WXGTK_BUILDLINK3_MK:M+)

# This is an exhaustive list of all of the versions of wxGTK
# that may be used.
#
_WXGTK_PKGS?=	WXGTK28 WXGTK30

WXGTK_DEFAULT?=	WXGTK28
WXGTK_ACCEPTED?=	${_WXGTK_PKGS}

_WXGTK_DEFAULT=	${WXGTK_DEFAULT}
_WXGTK_ACCEPTED=	${WXGTK_ACCEPTED}

_WXGTK_TYPE?=	${_WXGTK_DEFAULT}

.  if !empty(_WXGTK_ACCEPTED:M${_WXGTK_TYPE})
WXGTK_TYPE=	${_WXGTK_TYPE}
.  else
WXGTK_TYPE=	none
.  endif

BUILD_DEFS+=		WXGTK_DEFAULT
BUILD_DEFS_EFFECTS+=	WXGTKBASE WXGTK_TYPE

.if ${WXGTK_TYPE} == "none"
PKG_FAIL_REASON+=	\
	"${_WXGTK_TYPE} is not an acceptable version of wxGTK for ${PKGNAME}."
.elif ${WXGTK_TYPE} == "WXGTK28"
.  include "../../x11/wxGTK28/buildlink3.mk"
.elif ${WXGTK_TYPE} == "WXGTK30"
.  include "../../x11/wxGTK30/buildlink3.mk"
.endif

WXGTKBASE=	${BUILDLINK_PREFIX.${WXGTK_TYPE}}

.endif	# MK_WXGTK_BUILDLINK3_MK
