# $NetBSD: buildlink3.mk,v 1.10 2006/07/08 23:10:54 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GCCADA_BUILDLINK3_MK:=	${GCCADA_BUILDLINK3_MK}+
BUILDLINK_PREFIX.gcc34-ada:=${LOCALBASE}/gcc34-ada

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gcc34-ada
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngcc34-ada}
BUILDLINK_PACKAGES+=	gcc34-ada
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}gcc34-ada

.if !empty(GCCADA_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.gcc34-ada+=	gcc34-ada>=3.4.1nb4
BUILDLINK_ABI_DEPENDS.gcc34-ada?=	gcc34-ada>=3.4.4nb1
BUILDLINK_PKGSRCDIR.gcc34-ada?=	../../lang/gcc34-ada
BUILDLINK_ENV+= ADAC=${BUILDLINK_PREFIX.gcc34-ada}/bin/gcc
.  if exists(${BUILDLINK_PREFIX.gcc34-ada}/bin/gcc)
_GCC_ARCHDIR!=	${DIRNAME} `${BUILDLINK_PREFIX.gcc34-ada}/bin/gcc --print-libgcc-file-name`
.     if empty(_GCC_ARCHDIR:M*not_found*)
BUILDLINK_LIBDIRS.gcc34-ada+=	lib ${_GCC_ARCHDIR:S/^${BUILDLINK_PREFIX.gcc34-ada}\///}
BUILDLINK_LIBDIRS.gcc34-ada+=	${_GCC_ARCHDIR:S/^${BUILDLINK_PREFIX.gcc34-ada}\///}/adalib
BUILDLINK_INCDIRS.gcc34-ada+=	include ${_GCC_ARCHDIR:S/^${BUILDLINK_PREFIX.gcc34-ada}\///}/adainclude
.     endif
.  endif
.endif  # GCCADA_BUILDLINK3_MK

BUILDLINK_FILES_CMD.gcc34-ada=	(cd  ${BUILDLINK_PREFIX.gcc34-ada} && \
	${FIND} bin libexec lib \( -type file -o -type link \) -print)
BUILDLINK_TRANSFORM.gcc34-ada=	-e s:\buildlink:buildlink/gcc34-ada:

# Packages that link against shared libraries need a full dependency.
.  if defined(_USE_GCC_SHLIB)
BUILDLINK_DEPMETHOD.gcc34-ada?=	full
.  else
BUILDLINK_DEPMETHOD.gcc34-ada?=	build
.  endif

.include "../../mk/pthread.buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
