# $NetBSD: buildlink.mk,v 1.5 2001/06/10 00:09:33 jlam Exp $
#
# This Makefile fragment is included by packages that use libcups.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define CUPS_REQD to the version of cups desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Optionally define BUILDLINK_INCDIR and BUILDLINK_LIBDIR,
# (4) Add ${BUILDLINK_INCDIR} to the front of the C preprocessor's header
#     search path, and
# (5) Add ${BUILDLINK_LIBDIR} to the front of the linker's library search
#     path.

.if !defined(CUPS_BUILDLINK_MK)
CUPS_BUILDLINK_MK=	# defined

CUPS_REQD?=		1.1.1
DEPENDS+=		cups>=${CUPS_REQD}:../../print/cups

CUPS_HEADERS=		${LOCALBASE}/include/cups/*
CUPS_LIBS=		${LOCALBASE}/lib/libcups.*
CUPS_LIBS+=		${LOCALBASE}/lib/libcupsimage.*

BUILDLINK_INCDIR?=	${WRKDIR}/include
BUILDLINK_LIBDIR?=	${WRKDIR}/lib

CUPS_BUILDLINK_COOKIE=		${WRKDIR}/.cups_buildlink_done
CUPS_BUILDLINK_TARGETS=		link-cups-headers
CUPS_BUILDLINK_TARGETS+=	link-cups-libs
BUILDLINK_TARGETS+=		${CUPS_BUILDLINK_COOKIE}

pre-configure: ${CUPS_BUILDLINK_COOKIE}

${CUPS_BUILDLINK_COOKIE}: ${CUPS_BUILDLINK_TARGETS}
	@${TOUCH} ${TOUCH_FLAGS} ${CUPS_BUILDLINK_COOKIE}

# This target links the headers into ${BUILDLINK_INCDIR}, which should
# be searched first by the C preprocessor.
#
link-cups-headers:
	@${ECHO} "Linking cups headers into ${BUILDLINK_INCDIR}."
	@${MKDIR} ${BUILDLINK_INCDIR}/cups
	@${RM} -f ${BUILDLINK_INCDIR}/cups/*
	@for inc in ${CUPS_HEADERS}; do					\
		dest=${BUILDLINK_INCDIR}/cups/`${BASENAME} $${inc}`;	\
		if [ -f $${inc} ]; then					\
			${RM} -f $${dest};				\
			${LN} -sf $${inc} $${dest};			\
		fi;							\
	done

# This target links the libraries into ${BUILDLINK_LIBDIR}, which should
# be searched first by the linker.
#
link-cups-libs:
	@${ECHO} "Linking cups libraries into ${BUILDLINK_LIBDIR}."
	@${MKDIR} ${BUILDLINK_LIBDIR}
	@for lib in ${CUPS_LIBS}; do					\
		dest=${BUILDLINK_LIBDIR}/`${BASENAME} $${lib}`;		\
		if [ -f $${lib} ]; then					\
			${RM} -f $${dest};				\
			${LN} -sf $${lib} $${dest};			\
		fi;							\
	done

.endif	# CUPS_BUILDLINK_MK
