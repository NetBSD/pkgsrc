# $NetBSD: buildlink3.mk,v 1.5 2013/02/03 07:45:18 ryoon Exp $

BUILDLINK_TREE+=	gcc45

.if !defined(GCC45_BUILDLINK3_MK)
GCC45_BUILDLINK3_MK:=

FIND_PREFIX:=	BUILDLINK_PREFIX.gcc45=gcc45
.include "../../mk/find-prefix.mk"

_GCC45_SUBDIR=	gcc45
_GCC45_PREFIX=	${BUILDLINK_PREFIX.gcc45}/${_GCC45_SUBDIR}

BUILDLINK_API_DEPENDS.gcc45+=	gcc45>=${_GCC_REQD}
BUILDLINK_ABI_DEPENDS.gcc45+=	gcc45>=4.5.0
BUILDLINK_PKGSRCDIR.gcc45?=	../../lang/gcc45

.if exists(${_GCC45_PREFIX}/bin/gcc)

# logic for detecting the ADA compiler (not yet supported)
#gcc45_GNAT1!=${_GCC45_PREFIX}/bin/gcc -print-prog-name=gnat1
#.  if exists(${gcc45_GNAT1})
#CONFIGURE_ENV+=	ADAC=${_GCC45_PREFIX}/bin/gcc
#MAKE_ENV+=	ADAC=${_GCC45_PREFIX}/bin/gcc
#.  endif

# add libraries
BUILDLINK_LIBDIRS.gcc45+=	${_GCC45_SUBDIR}/lib

# find the gcc architecture
gcc45_GCC_ARCHDIR!=	${DIRNAME} `${_GCC45_PREFIX}/bin/gcc --print-libgcc-file-name`

# add the architecture dep libraries
.  if empty(gcc45_GCC_ARCHDIR:M*not_found*)
BUILDLINK_LIBDIRS.gcc45+=	${gcc45_GCC_ARCHDIR:S/^${BUILDLINK_PREFIX.gcc45}\///}/

# add the ada libraries (not yet supported)
#.    if exists(${gcc45_GNAT1})
#BUILDLINK_LIBDIRS.gcc45+=	${gcc45_GCC_ARCHDIR:S/^${BUILDLINK_PREFIX.gcc45}\///}/adalib
#.    endif

# add the header files
BUILDLINK_INCDIRS.gcc45+=	${_GCC45_SUBDIR}/include ${gcc45_GCC_ARCHDIR:S/^${BUILDLINK_PREFIX.gcc45}\///}/include
.  endif
.endif

BUILDLINK_FILES_CMD.gcc45=	\
	(cd  ${BUILDLINK_PREFIX.gcc45} &&	\
	${FIND} ${_GCC45_SUBDIR}/bin ${_GCC45_SUBDIR}/include ${_GCC45_SUBDIR}/libexec ${_GCC45_SUBDIR}/lib \( -type f -o -type l \) -print)

# When not using the GNU linker, gcc will always link shared libraries
# against the shared version of libgcc. Always enable _USE_GCC_SHILB on
# platforms that don't use the GNU linker, such as SunOS.
.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "SunOS"
_USE_GCC_SHLIB= yes
.endif

# Packages that link against shared libraries need a full dependency.
.if defined(_USE_GCC_SHLIB)
BUILDLINK_DEPMETHOD.gcc45+=	full
.else
BUILDLINK_DEPMETHOD.gcc45?=	build
.endif

.include "../../mk/pthread.buildlink3.mk"
pkgbase := gcc45
.include "../../mk/pkg-build-options.mk"
.if !empty(PKG_BUILD_OPTIONS.gcc45:Mnls)
.include "../../devel/gettext-lib/buildlink3.mk"
.endif
.endif # GCC45_BUILDLINK3_MK

BUILDLINK_TREE+=	-gcc45
