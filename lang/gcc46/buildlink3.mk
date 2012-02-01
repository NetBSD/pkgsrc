# $NetBSD: buildlink3.mk,v 1.4 2012/02/01 22:16:50 hans Exp $

BUILDLINK_TREE+=	gcc46

.if !defined(GCC46_BUILDLINK3_MK)
GCC46_BUILDLINK3_MK:=

FIND_PREFIX:=	BUILDLINK_PREFIX.gcc46=gcc46
.include "../../mk/find-prefix.mk"

_GCC46_SUBDIR=	gcc46
_GCC46_PREFIX=	${BUILDLINK_PREFIX.gcc46}/${_GCC46_SUBDIR}

BUILDLINK_API_DEPENDS.gcc46+=	gcc46>=${_GCC_REQD}
BUILDLINK_ABI_DEPENDS.gcc46?=	gcc46>=4.6.0
BUILDLINK_PKGSRCDIR.gcc46?=	../../lang/gcc46

.if exists(${_GCC46_PREFIX}/bin/gcc)

# logic for detecting the ADA compiler (not yet supported)
#gcc46_GNAT1!=${_GCC46_PREFIX}/bin/gcc -print-prog-name=gnat1
#.  if exists(${gcc46_GNAT1})
#CONFIGURE_ENV+=	ADAC=${_GCC46_PREFIX}/bin/gcc
#MAKE_ENV+=	ADAC=${_GCC46_PREFIX}/bin/gcc
#.  endif

# add libraries
BUILDLINK_LIBDIRS.gcc46+=	${_GCC46_SUBDIR}/lib

# find the gcc architecture
gcc46_GCC_ARCHDIR!=	${DIRNAME} `${_GCC46_PREFIX}/bin/gcc --print-libgcc-file-name`

# add the architecture dep libraries
.  if empty(gcc46_GCC_ARCHDIR:M*not_found*)
BUILDLINK_LIBDIRS.gcc46+=	${gcc46_GCC_ARCHDIR:S/^${BUILDLINK_PREFIX.gcc46}\///}/

# add the ada libraries (not yet supported)
#.    if exists(${gcc46_GNAT1})
#BUILDLINK_LIBDIRS.gcc46+=	${gcc46_GCC_ARCHDIR:S/^${BUILDLINK_PREFIX.gcc46}\///}/adalib
#.    endif

# add the header files
BUILDLINK_INCDIRS.gcc46+=	${_GCC46_SUBDIR}/include ${gcc46_GCC_ARCHDIR:S/^${BUILDLINK_PREFIX.gcc46}\///}/include
.  endif
.endif

BUILDLINK_FILES_CMD.gcc46=	\
	(cd  ${BUILDLINK_PREFIX.gcc46} &&	\
	${FIND} ${_GCC46_SUBDIR}/bin ${_GCC46_SUBDIR}/include ${_GCC46_SUBDIR}/libexec ${_GCC46_SUBDIR}/lib \( -type f -o -type l \) -print)

# When not using the GNU linker, gcc will always link shared libraries
# against the shared version of libgcc. Always enable _USE_GCC_SHILB on
# platforms that don't use the GNU linker, such as SunOS.
.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "SunOS"
_USE_GCC_SHLIB= yes
.endif

# Packages that link against shared libraries need a full dependency.
.if defined(_USE_GCC_SHLIB)
BUILDLINK_DEPMETHOD.gcc46+=	full
.else
BUILDLINK_DEPMETHOD.gcc46?=	build
.endif

.include "../../mk/pthread.buildlink3.mk"
pkgbase := gcc46
.include "../../mk/pkg-build-options.mk"
.if !empty(PKG_BUILD_OPTIONS.gcc46:Mnls)
.include "../../devel/gettext-lib/buildlink3.mk"
.endif
.endif # GCC46_BUILDLINK3_MK

BUILDLINK_TREE+=	-gcc46
