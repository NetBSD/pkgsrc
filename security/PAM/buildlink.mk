# $NetBSD: buildlink.mk,v 1.1 2001/05/24 16:41:08 jlam Exp $
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

PAM_REQD?=		0.72

PAM_INCDIR=		${LOCALBASE}/include/security
LIBPAM=			${LOCALBASE}/lib/libpam.a
LIBPAM+=		${LOCALBASE}/lib/libpam.so*
LIBPAMC=		${LOCALBASE}/lib/libpamc.a
LIBPAMC+=		${LOCALBASE}/lib/libpamc.so*
LIBPAMMISC=		${LOCALBASE}/lib/libpam_misc.a
LIBPAMMISC+=		${LOCALBASE}/lib/libpam_misc.so*
DEPENDS+=		PAM>=${PAM_REQD}:../../security/PAM

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
	@for inc in ${PAM_INCDIR}/*; do					\
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
	@for lib in ${LIBPAM} ${LIBPAMC} ${LIBPAMMISC}; do		\
		dest=${BUILDLINK_LIBDIR}/`${BASENAME} $${lib}`;		\
		if [ -f $${lib} ]; then					\
			${RM} -f $${dest};				\
			${LN} -sf $${lib} $${dest};			\
		fi;							\
	done
