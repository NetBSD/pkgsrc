# $NetBSD: buildlink.mk,v 1.5 2001/06/10 00:09:33 jlam Exp $
#
# This Makefile fragment is included by packages that use libpam.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define PAM_REQD to the version of pam desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Optionally define BUILDLINK_INCDIR and BUILDLINK_LIBDIR,
# (4) Add ${BUILDLINK_INCDIR} to the front of the C preprocessor's header
#     search path, and
# (5) Add ${BUILDLINK_LIBDIR} to the front of the linker's library search
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

PAM_BUILDLINK_COOKIE=		${WRKDIR}/.pam_buildlink_done
PAM_BUILDLINK_TARGETS=		link-pam-headers
PAM_BUILDLINK_TARGETS+=		link-pam-libs
BUILDLINK_TARGETS+=		${PAM_BUILDLINK_COOKIE}

pre-configure: ${PAM_BUILDLINK_COOKIE}

${PAM_BUILDLINK_COOKIE}: ${PAM_BUILDLINK_TARGETS}
	@${TOUCH} ${TOUCH_FLAGS} ${PAM_BUILDLINK_COOKIE}

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
