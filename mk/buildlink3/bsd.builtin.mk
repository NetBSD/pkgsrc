# $NetBSD: bsd.builtin.mk,v 1.1 2004/03/21 00:03:32 jlam Exp $
#
# Include this file to set the value of USE_BUILTIN.<pkg> for each
# package listed in BUILDLINK_PACKAGES.  Note that this file may
# indirectly add additional values to BUILDLINK_PACKAGES.
#
# For each package which may duplicate built-in software on the system,
# a builtin.mk file should be created.  The only requirements of a
# builtin.mk file are:
#
#   (1) It should set USE_BUILTIN.<pkg> to either "yes" or "no" after it
#       is included.
#   (2) It should *not* override any USE_BUILTIN.<pkg> which is already
#       set before the builtin.mk file is included.
#   (3) It should be written to allow multiple inclusion.
#
# An example package builtin.mk file is:
#
# -------------8<-------------8<-------------8<-------------8<-------------
# .if !defined(IS_BUILTIN.foo)
# #
# # IS_BUILTIN.foo is set to "yes" or "no" depending on whether "foo"
# # genuinely exists in the system or not.
# #
# IS_BUILTIN.foo?=	no
#
# # BUILTIN_PKG.foo should be set here if "foo" is built-in and its package
# # version can be determined.
# #
# .  if !empty(IS_BUILTIN.foo:M[yY][eE][sS])
# BUILTIN_PKG.foo?=	foo-1.0
# .  endif
# .endif  # IS_BUILTIN.foo
#
# .if !defined(USE_BUILTIN.foo)
# USE_BUILTIN.foo?=	${IS_BUILTIN.foo}
# .  if defined(BUILTIN_PKG.foo)
# .    for _depend_ in ${BUILDLINK_DEPENDS.foo}
# .      if !empty(USE_BUILTIN.foo:M[yY][eE][sS])
# USE_BUILTIN.foo!=							\
#	if ${PKG_ADMIN} pmatch '${_depend_}' ${BUILTIN_PKG.foo}; then	\
#		${ECHO} "yes";						\
#	else								\
#		${ECHO} "no";						\
#	fi
# .      endif
# .    endfor
# .  endif
# .endif  # USE_BUILTIN.foo
#
# CHECK_BUILTIN.foo?=	no
# .if !empty(CHECK_BUILTIN.foo:M[nN][oO])
# #
# # Here we place code that depends on whether USE_BUILTIN.foo is set to
# # "yes" or "no".
# #
# .endif  # CHECK_BUILTIN.foo
# -------------8<-------------8<-------------8<-------------8<-------------
#
# Note the structure of the builtin.mk file: first we set IS_BUILTIN.<pkg>,
# then USE_BUILTIN.<pkg>, then we isolate code that depends on the whether
# USE_BUILTIN.<pkg> is "yes" or "no" in a region that is guarded by
# CHECK_BUILTIN.<pkg>.  Package builtin.mk files aren't protected against
# multiple inclusion.

# Define PREFER.<pkg> to be either "pkgsrc" or "native" depending on
# whether to prefer the pkgsrc or native versions of software that's
# also part of the base system.  It's value is determined from the
# user-settable values PREFER_PKGSRC and PREFER_NATIVE.  Preferences are
# determined by the most specific instance of the package in either
# PREFER_PKGSRC or PREFER_NATIVE.  If a package is specified in neither
# or in both variables, then PREFER_PKGSRC has precedence over
# PREFER_NATIVE.
#
.for _pkg_ in ${BUILDLINK_PACKAGES}
PREFER.${_pkg_}?=	pkgsrc
.  if !empty(PREFER_NATIVE:M[yY][eE][sS])
PREFER.${_pkg_}=	native
.  endif
.  if !empty(PREFER_PKGSRC:M[yY][eE][sS])
PREFER.${_pkg_}=	pkgsrc
.  endif
.  if !empty(PREFER_NATIVE:M${_pkg_})
PREFER.${_pkg_}=	native
.  endif
.  if !empty(PREFER_PKGSRC:M${_pkg_})
PREFER.${_pkg_}=	pkgsrc
.  endif
.endfor

.for _pkg_ in ${BUILDLINK_PACKAGES}
.  if ${PREFER.${_pkg_}} == "pkgsrc"
USE_BUILTIN.${_pkg_}?=	no
.  endif
#
# builtin.mk files default to using the built-in software if it's
# available (${PREFER.<pkg>} == "native") unless USE_BUILTIN.<pkg> has
# been previously set.
#
.  if defined(BUILDLINK_PKGSRCDIR.${_pkg_})
.    if exists(${BUILDLINK_PKGSRCDIR.${_pkg_}}/builtin.mk)
.      include "${BUILDLINK_PKGSRCDIR.${_pkg_}}/builtin.mk"
.    endif
.  endif
.endfor

# Default fall-through for packages that don't provide a builtin.mk.  This
# is here to set the default for any package added to BUILDLINK_PACKAGES
# by any of the above code.
#
.for _pkg_ in ${BUILDLINK_PACKAGES}
USE_BUILTIN.${_pkg_}?=	no
.endfor
