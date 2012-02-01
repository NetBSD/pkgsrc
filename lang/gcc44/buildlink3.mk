# $NetBSD: buildlink3.mk,v 1.7 2012/02/01 21:17:05 hans Exp $

BUILDLINK_TREE+=	gcc44

.if !defined(GCC44_BUILDLINK3_MK)
GCC44_BUILDLINK3_MK:=

FIND_PREFIX:=	BUILDLINK_PREFIX.gcc44=gcc44
.include "../../mk/find-prefix.mk"

_GCC44_SUBDIR=	gcc44
_GCC44_PREFIX=	${BUILDLINK_PREFIX.gcc44}/${_GCC44_SUBDIR}

BUILDLINK_API_DEPENDS.gcc44+=	gcc44>=${_GCC_REQD}
BUILDLINK_ABI_DEPENDS.gcc44?=	gcc44>=4.4.5nb2
BUILDLINK_PKGSRCDIR.gcc44?=	../../lang/gcc44

.if exists(${_GCC44_PREFIX}/bin/gcc)

# logic for detecting the ADA compiler (not yet supported)
#gcc44_GNAT1!=${_GCC44_PREFIX}/bin/gcc -print-prog-name=gnat1
#.  if exists(${gcc44_GNAT1})
#CONFIGURE_ENV+=	ADAC=${_GCC44_PREFIX}/bin/gcc
#MAKE_ENV+=	ADAC=${_GCC44_PREFIX}/bin/gcc
#.  endif

# add libraries
BUILDLINK_LIBDIRS.gcc44+=	${_GCC44_SUBDIR}/lib

# find the gcc architecture
gcc44_GCC_ARCHDIR!=	${DIRNAME} `${_GCC44_PREFIX}/bin/gcc --print-libgcc-file-name`

# add the architecture dep libraries
.  if empty(gcc44_GCC_ARCHDIR:M*not_found*)
BUILDLINK_LIBDIRS.gcc44+=	${gcc44_GCC_ARCHDIR:S/^${BUILDLINK_PREFIX.gcc44}\///}/

# add the ada libraries (not yet supported)
#.    if exists(${gcc44_GNAT1})
#BUILDLINK_LIBDIRS.gcc44+=	${gcc44_GCC_ARCHDIR:S/^${BUILDLINK_PREFIX.gcc44}\///}/adalib
#.    endif

# add the header files
BUILDLINK_INCDIRS.gcc44+=	${_GCC44_SUBDIR}/include ${gcc44_GCC_ARCHDIR:S/^${BUILDLINK_PREFIX.gcc44}\///}/include
.  endif
.endif

BUILDLINK_FILES_CMD.gcc44=	\
	(cd  ${BUILDLINK_PREFIX.gcc44} &&	\
	${FIND} ${_GCC44_SUBDIR}/bin ${_GCC44_SUBDIR}/include ${_GCC44_SUBDIR}/libexec ${_GCC44_SUBDIR}/lib \( -type f -o -type l \) -print)

# When not using the GNU linker, gcc will always link shared libraries
# against the shared version of libgcc. Always enable _USE_GCC_SHILB on
# platforms that don't use the GNU linker, such as SunOS.
.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "SunOS"
_USE_GCC_SHLIB=	yes
.endif

# Packages that link against shared libraries need a full dependency.
.if defined(_USE_GCC_SHLIB)
BUILDLINK_DEPMETHOD.gcc44+=	full
.else
BUILDLINK_DEPMETHOD.gcc44?=	build
.endif

.include "../../mk/pthread.buildlink3.mk"
pkgbase := gcc44
.include "../../mk/pkg-build-options.mk"
.if !empty(PKG_BUILD_OPTIONS.gcc44:Mnls)
.include "../../devel/gettext-lib/buildlink3.mk"
.endif
.endif # GCC44_BUILDLINK3_MK

BUILDLINK_TREE+=	-gcc44
