# $NetBSD: buildlink2.mk,v 1.3 2002/08/27 17:31:58 jlam Exp $

.if !defined(F2C_BUILDLINK2_MK)
F2C_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		f2c
BUILDLINK_DEPENDS.f2c?=		f2c>=20001205nb3
BUILDLINK_PKGSRCDIR.f2c?=	../../lang/f2c

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

BUILDLINK_TARGETS+=	f2c-buildlink

PKG_FC=			${BUILDLINK_PREFIX.f2c}/bin/f2c-f77

# The f2c-f77 script takes some environment variables to override hardcoded
# values for the compiler and C preprocessor.
#
CONFIGURE_ENV+=		CC_f2c="${BUILDLINK_CC}"
CONFIGURE_ENV+=		CPP="${BUILDLINK_CPP}"
MAKE_ENV+=		CC_f2c="${BUILDLINK_CC}"
MAKE_ENV+=		CPP="${BUILDLINK_CPP}"

f2c-buildlink: _BUILDLINK_USE

.endif	# F2C_BUILDLINK2_MK
