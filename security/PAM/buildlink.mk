# $NetBSD: buildlink.mk,v 1.4 2001/06/09 15:30:53 wiz Exp $
#
# This Makefile fragment is included by packages that use libpam.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define PAM_REQD to the version of pam desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Optionally define BUILDLINK_INCDIR and BUILDLINK_LIBDIR,
# (4) Add ${BUILDLINK_TARGETS} to the prerequisite targets for pre-configure,
# (5) Add ${BUILDLINK_INCDIR} to the front of the C preprocessor's header
#     search path, and
# (6) Add ${BUILDLINK_LIBDIR} to the front of the linker's library search
#     path.

.if !defined(PAM_BUILDLINK_MK)
PAM_BUILDLINK_MK=	# defined

PAM_REQD?=		0.72
DEPENDS+=		PAM>=${PAM_REQD}:../../security/PAM

PAM_HEADERS=		${LOCALBASE}/include/security/*
PAM_LIBS=		${LOCALBASE}/lib/libpam.*
PAM_LIBS+=		${LOCALBASE}/lib/libpamc.*
PAM_LIBS+=		${LOCALBASE}/lib/libpam_misc.*

BUILDLINK_INCDIR?=	${WRKDIR}/include
BUILDLINK_LIBDIR?=	${WRKDIR}/lib

BUILDLINK_TARGETS+=	link-pam-headers
BUILDLINK_TARGETS+=	link-pam-libs

# This target links the headers into ${BUILDLINK_INCDIR}, which should
# be searched first by the C preprocessor.
#
link-pam-headers:
	@${ECHO} "Linking pam headers into ${BUILDLINK_INCDIR}."
	@${MKDIR} ${BUILDLINK_INCDIR}/security
	@${RM} -f ${BUILDLINK_INCDIR}/security/*
	@for inc in ${PAM_HEADERS}; do					\
		dest=${BUILDLINK_INCDIR}/security/`${BASENAME} $${inc}`; \
		if [ -f $${inc} ]; then					\
			${RM} -f $${dest};				\
			${LN} -sf $${inc} $${dest};			\
		fi;							\
	done

# This target links the libraries into ${BUILDLINK_LIBDIR}, which should
# be searched first by the linker.
#
link-pam-libs:
	@${ECHO} "Linking pam libraries into ${BUILDLINK_LIBDIR}."
	@${MKDIR} ${BUILDLINK_LIBDIR}
	@for lib in ${PAM_LIBS}; do					\
		dest=${BUILDLINK_LIBDIR}/`${BASENAME} $${lib}`;		\
		if [ -f $${lib} ]; then					\
			${RM} -f $${dest};				\
			${LN} -sf $${lib} $${dest};			\
		fi;							\
	done

.endif	# PAM_BUILDLINK_MK
