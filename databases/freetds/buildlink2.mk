# $NetBSD: buildlink2.mk,v 1.4 2002/09/22 10:06:01 jlam Exp $

.if !defined(FREETDS_BUILDLINK2_MK)
FREETDS_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		freetds
BUILDLINK_DEPENDS.freetds?=	freetds>=0.53nb1
BUILDLINK_PKGSRCDIR.freetds?=	../../databases/freetds

EVAL_PREFIX+=			BUILDLINK_PREFIX.freetds=freetds
BUILDLINK_PREFIX.freetds_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.freetds=	freetds/include/*
BUILDLINK_FILES.freetds+=	freetds/lib/*

BUILDLINK_CPPFLAGS.freetds=	-I${BUILDLINK_PREFIX.freetds}/freetds/include
BUILDLINK_LDFLAGS.freetds=	-L${BUILDLINK_PREFIX.freetds}/freetds/lib
BUILDLINK_LDFLAGS.freetds+=	-Wl,-R${BUILDLINK_PREFIX.freetds}/freetds/lib

BUILDLINK_TARGETS+=	freetds-buildlink

freetds-buildlink: _BUILDLINK_USE

.endif	# FREETDS_BUILDLINK2_MK
