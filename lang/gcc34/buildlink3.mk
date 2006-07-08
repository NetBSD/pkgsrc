# $NetBSD: buildlink3.mk,v 1.14 2006/07/08 23:10:54 jlam Exp $

BUILDLINK_DEPTH:=       ${BUILDLINK_DEPTH}+
GCC34_BUILDLINK3_MK:=  ${GCC34_BUILDLINK3_MK}+
BUILDLINK_PREFIX.gcc34:=${LOCALBASE}/gcc34

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=     gcc34
.endif

BUILDLINK_PACKAGES:=    ${BUILDLINK_PACKAGES:Ngcc34}
BUILDLINK_PACKAGES+=    gcc34
BUILDLINK_ORDER:=    ${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}gcc34

.if !empty(GCC34_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.gcc34+=	gcc34>=${_GCC_REQD}
BUILDLINK_ABI_DEPENDS.gcc34?=	gcc34>=3.4.5nb1
BUILDLINK_PKGSRCDIR.gcc34?=	../../lang/gcc34
.  if exists(${BUILDLINK_PREFIX.gcc34}/bin/gcc)
_GNAT1!=${BUILDLINK_PREFIX.gcc34}/bin/gcc -print-prog-name=gnat1
.    if exists(${_GNAT1})
BUILDLINK_ENV+=	ADAC=${BUILDLINK_PREFIX.gcc34}/bin/gcc
.    endif
BUILDLINK_LIBDIRS.gcc34+=	lib
_GCC_ARCHDIR!=	${DIRNAME} `${BUILDLINK_PREFIX.gcc34}/bin/gcc --print-libgcc-file-name`
.    if empty(_GCC_ARCHDIR:M*not_found*)
BUILDLINK_LIBDIRS.gcc34+=	${_GCC_ARCHDIR:S/^${BUILDLINK_PREFIX.gcc34}\///}/
.      if exists(${_GNAT1})
BUILDLINK_LIBDIRS.gcc34+=	${_GCC_ARCHDIR:S/^${BUILDLINK_PREFIX.gcc34}\///}/adalib
.      endif
BUILDLINK_INCDIRS.gcc34+=	include ${_GCC_ARCHDIR:S/^${BUILDLINK_PREFIX.gcc34}\///}/include
.    endif
.  endif
.endif  # GCC34_BUILDLINK3_MK

BUILDLINK_FILES_CMD.gcc34=	\
	(cd  ${BUILDLINK_PREFIX.gcc34} &&	\
	${FIND} bin libexec lib \( -type f -o -type l \) -print)
BUILDLINK_TRANSFORM.gcc34=	-e s:\buildlink:buildlink/gcc34:

# Packages that link against shared libraries need a full dependency.
.  if defined(_USE_GCC_SHLIB)
BUILDLINK_DEPMETHOD.gcc+=	full
.  else
BUILDLINK_DEPMETHOD.gcc?=	build
.  endif


.include "../../mk/pthread.buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"

BUILDLINK_DEPTH:=       ${BUILDLINK_DEPTH:S/+$//}
