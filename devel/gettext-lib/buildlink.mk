# $NetBSD: buildlink.mk,v 1.2 2001/05/28 06:07:16 jlam Exp $
#
# This Makefile fragment is included by packages that use gettext.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define GETTEXT_REQD to the version of gettext desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Optionally define BUILDLINK_INCDIR and BUILDLINK_LIBDIR,
# (4) Add ${BUILDLINK_TARGETS} to the prerequisite targets for pre-configure,
# (5) Add ${BUILDLINK_INCDIR} to the front of the C preprocessor's header
#     search path, and
# (6) Add ${BUILDLINK_LIBDIR} to the front of the linker's library search
#     path.

.if !defined(GETTEXT_BUILDLINK_MK)
GETTEXT_BUILDLINK_MK=	# defined

GETTEXT_REQD?=		0.10.35nb1

.if defined(USE_GNU_GETTEXT)
_NEED_GNU_GETTEXT=	YES
.elif exists(/usr/include/libintl.h)
_NEED_GNU_GETTEXT=	NO
.else
_NEED_GNU_GETTEXT=	YES
.endif

.if ${_NEED_GNU_GETTEXT} == "YES"
DEPENDS+=		gettext-lib>=${GETTEXT_REQD}:../../devel/gettext-lib
GETTEXT_HEADERS=	${LOCALBASE}/include/libintl.h
GETTEXT_LIBS=		${LOCALBASE}/lib/libintl.*
.else
GETTEXT_HEADERS=	/usr/include/libintl.h
GETTEXT_LIBS=		/usr/lib/libintl.*
.endif

BUILDLINK_INCDIR?=	${WRKDIR}/include
BUILDLINK_LIBDIR?=	${WRKDIR}/lib

.if defined(GNU_CONFIGURE)
CONFIGURE_ENV+=		CPPFLAGS="${CPPFLAGS}"
CONFIGURE_ENV+=		LIBS="${LIBS}"
CFLAGS+=		-I${BUILDLINK_INCDIR}
CPPFLAGS+=		-I${BUILDLINK_INCDIR}
LDFLAGS+=		-L${BUILDLINK_LIBDIR}
LIBS+=			-lintl
.endif

BUILDLINK_TARGETS+=	link-gettext-headers
BUILDLINK_TARGETS+=	link-gettext-libs

# This target links the headers into ${BUILDLINK_INCDIR}, which should
# be searched first by the C preprocessor.
#
link-gettext-headers:
	@${ECHO} "Linking gettext headers into ${BUILDLINK_INCDIR}."
	@${MKDIR} ${BUILDLINK_INCDIR}
	@for inc in ${GETTEXT_HEADERS}; do				\
		dest=${BUILDLINK_INCDIR}/`${BASENAME} $${inc}`;		\
		if [ -f $${inc} ]; then					\
			${RM} -f $${dest};				\
			${LN} -sf $${inc} $${dest};			\
		fi;							\
        done

# This target links the libraries into ${BUILDLINK_LIBDIR}, which should
# be searched first by the linker.
#
link-gettext-libs:
	@${ECHO} "Linking gettext libraries into ${BUILDLINK_LIBDIR}."
	@${MKDIR} ${BUILDLINK_LIBDIR}
	@for lib in ${GETTEXT_LIBS}; do					\
		dest=${BUILDLINK_LIBDIR}/`${BASENAME} $${lib}`;		\
		if [ -f $${lib} ]; then					\
			${RM} -f $${dest};				\
			${LN} -sf $${lib} $${dest};			\
		fi;							\
	done

.endif	# GETTEXT_BUILDLINK_MK
