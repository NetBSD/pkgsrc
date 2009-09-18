# $NetBSD: buildlink3.mk,v 1.1.1.1 2009/09/18 11:24:50 dmcmahill Exp $

BUILDLINK_TREE+=	gcc44

.if !defined(GCC44_BUILDLINK3_MK)
GCC44_BUILDLINK3_MK:=

FIND_PREFIX:=  BUILDLINK_PREFIX.gcc44=gcc44
.include "../../mk/find-prefix.mk"

BUILDLINK_API_DEPENDS.gcc44+=	gcc44>=${_GCC_REQD}
BUILDLINK_ABI_DEPENDS.gcc44?=	gcc44>=4.4.0
BUILDLINK_PKGSRCDIR.gcc44?=	../../lang/gcc44

.  if exists(${BUILDLINK_PREFIX.gcc44}/bin/gcc)

# logic for detecting the ADA compiler (not yet supported)
#gcc44_GNAT1!=${BUILDLINK_PREFIX.gcc44}/bin/gcc -print-prog-name=gnat1
#.    if exists(${gcc44_GNAT1})
#CONFIGURE_ENV+=	ADAC=${BUILDLINK_PREFIX.gcc44}/bin/gcc
#MAKE_ENV+=	ADAC=${BUILDLINK_PREFIX.gcc44}/bin/gcc
#.    endif

# add libraries
BUILDLINK_LIBDIRS.gcc44+=	lib

# find the gcc architecture
gcc44_GCC_ARCHDIR!=	${DIRNAME} `${BUILDLINK_PREFIX.gcc44}/bin/gcc --print-libgcc-file-name`

# add the architecture dep libraries
.    if empty(gcc44_GCC_ARCHDIR:M*not_found*)
BUILDLINK_LIBDIRS.gcc44+=	${gcc44_GCC_ARCHDIR:S/^${BUILDLINK_PREFIX.gcc44}\///}/

# add the ada libraries (not yet supported)
#.      if exists(${gcc44_GNAT1})
#BUILDLINK_LIBDIRS.gcc44+=	${gcc44_GCC_ARCHDIR:S/^${BUILDLINK_PREFIX.gcc44}\///}/adalib
#.      endif

# add the header files
BUILDLINK_INCDIRS.gcc44+=	include ${gcc44_GCC_ARCHDIR:S/^${BUILDLINK_PREFIX.gcc44}\///}/include
.    endif
.  endif

BUILDLINK_FILES_CMD.gcc44=	\
	(cd  ${BUILDLINK_PREFIX.gcc44} &&	\
	${FIND} bin libexec lib \( -type f -o -type l \) -print)
BUILDLINK_FNAME_TRANSFORM.gcc44=	-e s:buildlink:buildlink/gcc44:

# Packages that link against shared libraries need a full dependency.
.  if defined(_USE_GCC_SHLIB)
BUILDLINK_DEPMETHOD.gcc44+=	full
.  else
BUILDLINK_DEPMETHOD.gcc44?=	build
.  endif

.include "../../mk/pthread.buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.endif # GCC44_BUILDLINK3_MK

BUILDLINK_TREE+=	-gcc44
