# $NetBSD: buildlink2.mk,v 1.8 2003/07/13 13:50:55 wiz Exp $

.if !defined(FREETDS_BUILDLINK2_MK)
FREETDS_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		freetds
BUILDLINK_DEPENDS.freetds?=		freetds>=0.61nb1
BUILDLINK_PKGSRCDIR.freetds?=	../../databases/freetds

EVAL_PREFIX+=			BUILDLINK_PREFIX.freetds=freetds
BUILDLINK_PREFIX.freetds_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.freetds=	freetds/include/*
BUILDLINK_FILES.freetds+=	freetds/lib/*

BUILDLINK_CPPFLAGS.freetds=	-I${BUILDLINK_PREFIX.freetds}/freetds/include
BUILDLINK_LDFLAGS.freetds=	-L${BUILDLINK_PREFIX.freetds}/freetds/lib
BUILDLINK_LDFLAGS.freetds+=	-Wl,${RPATH_FLAG}${BUILDLINK_PREFIX.freetds}/freetds/lib
FIX_RPATH+=			BUILDLINK_LDFLAGS.freetds

BUILDLINK_TARGETS+=	freetds-buildlink

freetds-buildlink: _BUILDLINK_USE

.endif	# FREETDS_BUILDLINK2_MK
