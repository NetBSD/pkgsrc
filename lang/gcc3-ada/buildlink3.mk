# $NetBSD: buildlink3.mk,v 1.9 2009/03/20 19:24:49 joerg Exp $

BUILDLINK_PREFIX.gcc3-ada:=${LOCALBASE}/gcc3

BUILDLINK_TREE+=	gcc3-ada

.if !defined(GCC3_ADA_BUILDLINK3_MK)
GCC3_ADA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gcc3-ada+=      gcc3-ada>=3.3.3
BUILDLINK_ABI_DEPENDS.gcc3-ada?=    gcc3-ada>=3.3.5nb1
BUILDLINK_PKGSRCDIR.gcc3-ada?=    ../../lang/gcc3-ada
BUILDLINK_ENV+= ADAC=${LOCALBASE}/gcc3/bin/gcc
_GCC_ARCHDIR!=	${DIRNAME} `${LOCALBASE}/gcc3/bin/gcc --print-libgcc-file-name`
.  if empty(_GCC_ARCHDIR:M*not_found*)
BUILDLINK_LIBDIRS.gcc3-ada+=       lib ${_GCC_ARCHDIR:S/^${BUILDLINK_PREFIX.gcc3-ada}\///}
BUILDLINK_LIBDIRS.gcc3-ada+=       ${_GCC_ARCHDIR:S/^${BUILDLINK_PREFIX.gcc3-ada}\///}/adalib
BUILDLINK_INCDIRS.gcc3-ada+=       include ${_GCC_ARCHDIR:S/^${BUILDLINK_PREFIX.gcc3-ada}\///}/adainclude
.  endif

BUILDLINK_PKGSRCDIR.gcc3-ada?=     ../../lang/gcc3-ada
BUILDLINK_FILES_CMD.gcc3-ada=	(cd  ${BUILDLINK_PREFIX.gcc3-ada} && \
	${FIND} bin libexec lib \( -type file -o -type link \) -print)
BUILDLINK_FNAME_TRANSFORM.gcc3-ada=	-e s:\buildlink:buildlink/gcc3:

BUILDLINK_DEPMETHOD.gcc3-ada?=	build

.include "../../mk/pthread.buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.endif # GCC3_ADA_BUILDLINK3_MK

BUILDLINK_TREE+=	-gcc3-ada
