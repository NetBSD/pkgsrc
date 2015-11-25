# $NetBSD: buildlink3.mk,v 1.23 2015/11/25 12:51:16 jperkin Exp $

BUILDLINK_TREE+=	gcc34

.if !defined(GCC34_BUILDLINK3_MK)
GCC34_BUILDLINK3_MK:=

_GCC34_SUBDIR=	gcc34
_GCC34_PREFIX=	${BUILDLINK_PREFIX.gcc34}/${_GCC34_SUBDIR}

BUILDLINK_API_DEPENDS.gcc34+=	gcc34>=3.4
BUILDLINK_ABI_DEPENDS.gcc34+=	gcc34>=3.4.6nb4
BUILDLINK_PKGSRCDIR.gcc34?=	../../lang/gcc34

.  if exists(${_GCC34_PREFIX}/bin/gcc)
# logic for detecting the ADA compiler
gcc34_GNAT1!=${_GCC34_PREFIX}/bin/gcc -print-prog-name=gnat1
.    if exists(${gcc34_GNAT1})
BUILDLINK_ENV+=	ADAC=${_GCC34_PREFIX}/bin/gcc
.    endif

# add libraries
BUILDLINK_LIBDIRS.gcc34+=	${_GCC34_SUBDIR}/lib

# find the gcc architecture
gcc34_GCC_ARCHDIR!=	${DIRNAME} `${_GCC34_PREFIX}/bin/gcc --print-libgcc-file-name`

# add the architecture dep libraries
.    if empty(gcc34_GCC_ARCHDIR:M*not_found*)
BUILDLINK_LIBDIRS.gcc34+=	${gcc34_GCC_ARCHDIR:S/^${BUILDLINK_PREFIX.gcc34}\///}/

# add the ada libraries
.      if exists(${gcc34_GNAT1})
BUILDLINK_LIBDIRS.gcc34+=	${gcc34_GCC_ARCHDIR:S/^${BUILDLINK_PREFIX.gcc34}\///}/adalib
.      endif

# add the header files
BUILDLINK_INCDIRS.gcc34+=	${_GCC34_SUBDIR}/include ${gcc34_GCC_ARCHDIR:S/^${BUILDLINK_PREFIX.gcc34}\///}/include
.    endif
.  endif

BUILDLINK_FILES_CMD.gcc34=	\
	(cd  ${BUILDLINK_PREFIX.gcc34} &&	\
	${FIND} bin libexec lib \( -type f -o -type l \) -print)

# When not using the GNU linker, gcc will always link shared libraries
# against the shared version of libgcc. Always enable _USE_GCC_SHILB on
# platforms that don't use the GNU linker, such as SunOS.
.include "../../mk/bsd.fast.prefs.mk"
.if ${OPSYS} == "SunOS"
_USE_GCC_SHLIB= yes
.endif

# Packages that link against shared libraries need a full dependency.
.  if defined(_USE_GCC_SHLIB)
BUILDLINK_DEPMETHOD.gcc34+=	full
.  else
BUILDLINK_DEPMETHOD.gcc34?=	build
.  endif

.include "../../mk/pthread.buildlink3.mk"
pkgbase := gcc34
.include "../../mk/pkg-build-options.mk"
.if !empty(PKG_BUILD_OPTIONS.gcc34:Mnls)
.include "../../devel/gettext-lib/buildlink3.mk"
.endif
.endif # GCC34_BUILDLINK3_MK

BUILDLINK_TREE+=	-gcc34
