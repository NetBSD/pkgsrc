# $NetBSD: buildlink3.mk,v 1.1.1.1 2004/06/01 19:18:15 shannonjr Exp $

BUILDLINK_DEPTH:=       ${BUILDLINK_DEPTH}+
GCC34_BUILDLINK3_MK:=  ${GCC34_BUILDLINK3_MK}+
BUILDLINK_PREFIX.gcc-3.4:=${LOCALBASE}/gcc-3.4.0

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=     gcc-3.4
.endif

BUILDLINK_PACKAGES:=    ${BUILDLINK_PACKAGES:Ngcc-3.4}
BUILDLINK_PACKAGES+=    gcc-3.4

.if !empty(GCC34_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.gcc-3.4+=      gcc-3.4.0
BUILDLINK_PKGSRCDIR.gcc-3.4?=    ../../lang/gcc-3.4
_GNAT1!=${LOCALBASE}/gcc-3.4.0/bin/gcc -print-prog-name=gnat1
.  if exists(${_GNAT1})
BUILDLINK_ENV+=	ADAC=${LOCALBASE}/gcc-3.4.0/bin/gcc
.  endif
_GCC_ARCHDIR!=	${DIRNAME} `${LOCALBASE}/gcc-3.4.0/bin/gcc --print-libgcc-file-name`
.  if empty(_GCC_ARCHDIR:M*not_found*)
BUILDLINK_LIBDIRS.gcc-3.4+=	lib ${_GCC_ARCHDIR:S/^${BUILDLINK_PREFIX.gcc-3.4}\///}/
.    if exists(${_GNAT1})
BUILDLINK_LIBDIRS.gcc-3.4+=	${_GCC_ARCHDIR:S/^${BUILDLINK_PREFIX.gcc-3.4}\///}/adalib
.    endif
BUILDLINK_INCDIRS.gcc-3.4+=	include ${_GCC_ARCHDIR:S/^${BUILDLINK_PREFIX.gcc-3.4}\///}/include
.  endif
.endif  # GCC34_BUILDLINK3_MK

BUILDLINK_PKGSRCDIR.gcc-3.4?=     ../../lang/gcc-3.4
BUILDLINK_FILES_CMD.gcc-3.4=	\
	(cd  ${BUILDLINK_PREFIX.gcc-3.4} &&	\
	${FIND} bin libexec lib \( -type file -o -type link \) -print)
BUILDLINK_TRANSFORM.gcc-3.4=	-e s:\buildlink:buildlink/gcc-3.4.0:

# Packages that link against shared libraries need a full dependency.
BUILDLINK_DEPMETHOD.gcc-3.4?=	full

.include "../../mk/pthread.buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
