# $NetBSD: buildlink.mk,v 1.5 2001/11/30 17:21:56 jlam Exp $
#
# This Makefile fragment is included by packages that use f2c.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.f2c to the dependency pattern
#     for the version of f2c desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(F2C_BUILDLINK_MK)
F2C_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.f2c?=	f2c>=20001205nb3
DEPENDS+=		${BUILDLINK_DEPENDS.f2c}:../../lang/f2c

EVAL_PREFIX+=		BUILDLINK_PREFIX.f2c=f2c
BUILDLINK_PREFIX.f2c_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.f2c=	include/f2c.h
BUILDLINK_FILES.f2c+=	lib/libf2c.*
BUILDLINK_FILES.f2c+=	lib/libf2c_p.a
BUILDLINK_FILES.f2c+=	lib/libf2c_pic.a
BUILDLINK_FILES.f2c+=	lib/libF77.*
BUILDLINK_FILES.f2c+=	lib/libF77_p.a
BUILDLINK_FILES.f2c+=	lib/libF77_pic.a
BUILDLINK_FILES.f2c+=	lib/libI77.*
BUILDLINK_FILES.f2c+=	lib/libI77_p.a
BUILDLINK_FILES.f2c+=	lib/libI77_pic.a

BUILDLINK_TARGETS.f2c=	f2c-buildlink
BUILDLINK_TARGETS.f2c+=	f2c-f77-buildlink
BUILDLINK_TARGETS+=	${BUILDLINK_TARGETS.f2c}

# Set the f2c-f77 script to the buildlink'ed wrapper script.
PKG_FC=			${BUILDLINK_DIR}/bin/f2c-f77

pre-configure: ${BUILDLINK_TARGETS.f2c}
f2c-buildlink: _BUILDLINK_USE

f2c-f77-buildlink:
	${_PKG_SILENT}${_PKG_DEBUG}					\
	cookie=${BUILDLINK_DIR}/.f2c_f77_buildlink_done;		\
	if [ ! -f $${cookie} ]; then					\
		file=bin/f2c-f77;					\
		dest=${BUILDLINK_DIR}/$${file};				\
		${ECHO_BUILDLINK_MSG} "Creating script $${dest}.";		\
		dir=`${DIRNAME} $${dest}`;				\
		if [ ! -d $${dir} ]; then				\
			${MKDIR} $${dir};				\
		fi;							\
		${SED}	-e "s|-I${BUILDLINK_PREFIX.f2c}/include|-I${BUILDLINK_DIR}/include|g" \
			-e "s|-L${BUILDLINK_PREFIX.f2c}/lib|-L${BUILDLINK_DIR}/lib|g" \
			${BUILDLINK_PREFIX.f2c}/$${file} > $${dest};	\
		${CHMOD} +x $${dest};					\
		${ECHO} $${dest} >> $${cookie};				\
	fi

.endif	# F2C_BUILDLINK_MK
