# $NetBSD: buildlink2.mk,v 1.2 2003/07/13 13:52:20 wiz Exp $

.if !defined(GAWK_BUILDLINK2_MK)
GAWK_BUILDLINK2_MK=	# defined

.include "../../mk/bsd.prefs.mk"

BUILDLINK_DEPENDS.gawk?=	gawk>=3.1.1nb1
BUILDLINK_PKGSRCDIR.gawk?=	../../lang/gawk

#
# Some packages may really need GNU awk, but most just demand a
# working awk.
#

.if defined(USE_GNU_AWK)
_NEED_GNU_AWK=		YES
.else
_NEED_GNU_AWK=		NO

# Not sure about IRIX, mark it incompatible for now
_INCOMPAT_AWK=		IRIX-*-*

INCOMPAT_AWK?=		# empty
.  for _pattern_ in ${_INCOMPAT_AWK} ${INCOMPAT_AWK}
.    if !empty(MACHINE_PLATFORM:M${_pattern_})
_NEED_GNU_AWK=		YES
.    endif
.  endfor

.endif

.if ${_NEED_GNU_AWK} == "YES"
BUILDLINK_DEPMETHOD.gawk?=	build
BUILDLINK_PACKAGES+=		gawk
BUILDLINK_PREFIX.gawk_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.gawk=		bin/${GNU_PROGRAM_PREFIX}awk
EVAL_PREFIX+=			BUILDLINK_PREFIX.gawk=gawk
.endif

BUILDLINK_TARGETS+=	gawk-buildlink gawk-buildlink-bin

gawk-buildlink: _BUILDLINK_USE

gawk-buildlink-bin:
.if ${_NEED_GNU_AWK} == "YES"
	${_PKG_SILENT}${_PKG_DEBUG}				\
	[ ! -f ${BUILDLINK_DIR}/bin/awk ] &&			\
	  ${LN} -fs ${GNU_PROGRAM_PREFIX}awk ${BUILDLINK_DIR}/bin/awk
.else
	${_PKG_SILENT}${_PKG_DEBUG}				\
	[ ! -f ${BUILDLINK_DIR}/bin/awk ] &&			\
	  ${LN} -fs ${AWK} ${BUILDLINK_DIR}/bin/awk
.endif

.endif	# GAWK_BUILDLINK2_MK
