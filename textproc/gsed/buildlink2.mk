# $NetBSD: buildlink2.mk,v 1.2 2003/07/09 08:07:09 grant Exp $

.if !defined(GSED_BUILDLINK2_MK)
GSED_BUILDLINK2_MK=	# defined

.include "../../mk/bsd.prefs.mk"

BUILDLINK_DEPENDS.gsed?=	gsed>=3.02
BUILDLINK_PKGSRCDIR.gsed?=	../../textproc/gsed

#
# Some packages may really need GNU sed, but most just demand a
# working sed.
#

.if defined(USE_GNU_SED)
_NEED_GNU_SED=		YES
.else
_NEED_GNU_SED=		NO

# Not sure about IRIX, mark it incompatible for now
_INCOMPAT_SED=		IRIX-*-*

INCOMPAT_SED?=		# empty
.  for _pattern_ in ${_INCOMPAT_SED} ${INCOMPAT_SED}
.    if !empty(MACHINE_PLATFORM:M${_pattern_})
_NEED_GNU_SED=		YES
.    endif
.  endfor

.endif

.if ${_NEED_GNU_SED} == "YES"
BUILDLINK_DEPMETHOD.gsed?=	build
BUILDLINK_PACKAGES+=		gsed
BUILDLINK_PREFIX.gsed_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.gsed=		bin/${GNU_PROGRAM_PREFIX}sed
EVAL_PREFIX+=			BUILDLINK_PREFIX.gsed=gsed
.endif

BUILDLINK_TARGETS+=	gsed-buildlink gsed-buildlink-bin

gsed-buildlink: _BUILDLINK_USE

gsed-buildlink-bin:
.if ${_NEED_GNU_SED} == "YES"
	${_PKG_SILENT}${_PKG_DEBUG}				\
	[ ! -f ${BUILDLINK_DIR}/bin/sed ] &&			\
	  ${LN} -fs ${GNU_PROGRAM_PREFIX}sed ${BUILDLINK_DIR}/bin/sed
.else
	${_PKG_SILENT}${_PKG_DEBUG}				\
	[ ! -f ${BUILDLINK_DIR}/bin/sed ] &&			\
	  ${LN} -fs ${SED} ${BUILDLINK_DIR}/bin/sed
.endif

.endif	# GSED_BUILDLINK2_MK
