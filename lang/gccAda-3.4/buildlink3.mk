# $NetBSD: buildlink3.mk,v 1.1.1.1 2004/06/01 18:32:03 shannonjr Exp $

BUILDLINK_DEPTH:=       ${BUILDLINK_DEPTH}+
GCCADA_BUILDLINK3_MK:=  ${GCCADA_BUILDLINK3_MK}+
BUILDLINK_PREFIX.gccAda-3.4.0:=${LOCALBASE}/gccAda-3.4.0

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=     gccAda-3.4.0
.endif

BUILDLINK_PACKAGES:=    ${BUILDLINK_PACKAGES:NgccAda-3.4.0}
BUILDLINK_PACKAGES+=    gccAda-3.4.0

.if !empty(GCCADA_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.gccAda-3.4.0+=      gccAda>=3.4.0
BUILDLINK_PKGSRCDIR.gccAda-3.4.0?=    ../../lang/gccAda-3.4
BUILDLINK_ENV+= ADAC=${LOCALBASE}/gccAda-3.4.0/bin/gcc
_GCC_ARCHDIR!=	${DIRNAME} `${LOCALBASE}/gccAda-3.4.0/bin/gcc --print-libgcc-file-name`
.  if empty(_GCC_ARCHDIR:M*not_found*)
BUILDLINK_LIBDIRS.gccAda-3.4.0+=       lib ${_GCC_ARCHDIR:S/^${BUILDLINK_PREFIX.gccAda-3.4.0}\///}
BUILDLINK_LIBDIRS.gccAda-3.4.0+=       ${_GCC_ARCHDIR:S/^${BUILDLINK_PREFIX.gccAda-3.4.0}\///}/adalib
BUILDLINK_INCDIRS.gccAda-3.4.0+=       include ${_GCC_ARCHDIR:S/^${BUILDLINK_PREFIX.gccAda-3.4.0}\///}/adainclude
.  endif
.endif  # GCCADA_BUILDLINK3_MK

BUILDLINK_PKGSRCDIR.gccAda-3.4.0?=     ../../lang/gccAda-3.4.0
BUILDLINK_FILES_CMD.gccAda-3.4.0=	(cd  ${BUILDLINK_PREFIX.gccAda-3.4.0} && \
	${FIND} bin libexec lib \( -type file -o -type link \) -print)
BUILDLINK_TRANSFORM.gccAda-3.4.0=	-e s:\buildlink:buildlink/gccAda-3.4.0:

# Packages that link against shared libraries need a full dependency.
.  if defined(USE_GCC_SHLIB)
BUILDLINK_DEPMETHOD.gccAda-3.4.0?=	full
.  else
BUILDLINK_DEPMETHOD.gccAda-3.4.0?=	build
.  endif

.include "../../mk/pthread.buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
