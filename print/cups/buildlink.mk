# $NetBSD: buildlink.mk,v 1.1 2001/05/24 16:41:08 jlam Exp $
#
# This Makefile fragment is included by packages that use libcups.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define CUPS_REQD to the version of cups desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Optionally define BUILDLINK_INCDIR and BUILDLINK_LIBDIR,
# (4) Add ${BUILDLINK_TARGETS} to the prerequisite targets for pre-configure,
# (5) Add ${BUILDLINK_INCDIR} to the front of the C preprocessor's header
#     search path, and
# (6) Add ${BUILDLINK_LIBDIR} to the front of the linker's library search
#     path.

CUPS_REQD?=		1.1.1

CUPS_INCDIR=		${LOCALBASE}/include/cups
LIBCUPS=		${LOCALBASE}/lib/libcups.a
LIBCUPS=		${LOCALBASE}/lib/libcups.so*
LIBCUPSIMAGE=		${LOCALBASE}/lib/libcupsimage.a
LIBCUPSIMAGE=		${LOCALBASE}/lib/libcupsimage.so*
DEPENDS+=		cups>=${CUPS_REQD}:../../print/cups

BUILDLINK_INCDIR?=	${WRKDIR}/include
BUILDLINK_LIBDIR?=	${WRKDIR}/lib

BUILDLINK_TARGETS+=	link-cups-headers
BUILDLINK_TARGETS+=	link-cups-libs

# This target links the headers into ${BUILDLINK_INCDIR}, which should
# be searched first by the C preprocessor.
#
link-cups-headers:
	@${ECHO} "Linking cups headers into ${BUILDLINK_INCDIR}."
	@${MKDIR} ${BUILDLINK_INCDIR}/cups
	@for inc in ${CUPS_INCDIR}/*; do				\
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
	@for lib in ${LIBCUPS} ${LIBCUPSIMAGE}; do			\
		dest=${BUILDLINK_LIBDIR}/`${BASENAME} $${lib}`;		\
		if [ -f $${lib} ]; then					\
			${RM} -f $${dest};				\
			${LN} -sf $${lib} $${dest};			\
		fi;							\
	done
