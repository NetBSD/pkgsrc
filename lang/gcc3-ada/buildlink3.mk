# $NetBSD: buildlink3.mk,v 1.2 2005/05/09 23:46:46 rillig Exp $

BUILDLINK_DEPTH:=       ${BUILDLINK_DEPTH}+
GCC3_ADA_BUILDLINK3_MK:=  ${GCC3_ADA_BUILDLINK3_MK}+
BUILDLINK_PREFIX.gcc3-ada:=${LOCALBASE}/gcc3

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=     gcc3-ada
.endif

BUILDLINK_PACKAGES:=    ${BUILDLINK_PACKAGES:Ngcc3-ada}
BUILDLINK_PACKAGES+=    gcc3-ada

.if !empty(GCC3_ADA_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.gcc3-ada+=      gcc3-ada>=3.3.3
BUILDLINK_PKGSRCDIR.gcc3-ada?=    ../../lang/gcc3-ada
BUILDLINK_ENV+= ADAC=${LOCALBASE}/gcc3/bin/gcc
_GCC_ARCHDIR!=	${DIRNAME} `${LOCALBASE}/gcc3/bin/gcc --print-libgcc-file-name`
.  if empty(_GCC_ARCHDIR:M*not_found*)
BUILDLINK_LIBDIRS.gcc3-ada+=       lib ${_GCC_ARCHDIR:S/^${BUILDLINK_PREFIX.gcc3-ada}\///}
BUILDLINK_LIBDIRS.gcc3-ada+=       ${_GCC_ARCHDIR:S/^${BUILDLINK_PREFIX.gcc3-ada}\///}/adalib
BUILDLINK_INCDIRS.gcc3-ada+=       include ${_GCC_ARCHDIR:S/^${BUILDLINK_PREFIX.gcc3-ada}\///}/adainclude
.  endif
.endif  # GCC3_ADA_BUILDLINK3_MK

BUILDLINK_PKGSRCDIR.gcc3-ada?=     ../../lang/gcc3-ada
BUILDLINK_FILES_CMD.gcc3-ada=	(cd  ${BUILDLINK_PREFIX.gcc3-ada} && \
	${FIND} bin libexec lib \( -type file -o -type link \) -print)
BUILDLINK_TRANSFORM.gcc3-ada=	-e s:\buildlink:buildlink/gcc3:

BUILDLINK_DEPMETHOD.gcc3-ada?=	build

.include "../../mk/pthread.buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
