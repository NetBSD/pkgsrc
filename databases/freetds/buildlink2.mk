# $NetBSD: buildlink2.mk,v 1.3 2002/09/20 00:15:56 grant Exp $

.if !defined(FREETDS_BUILDLINK2_MK)
FREETDS_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		freetds
BUILDLINK_DEPENDS.freetds?=	freetds>=0.53nb1
BUILDLINK_PKGSRCDIR.freetds?=	../../databases/freetds

EVAL_PREFIX+=			BUILDLINK_PREFIX.freetds=freetds
BUILDLINK_PREFIX.freetds_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.freetds=	freetds/include/*
BUILDLINK_FILES.freetds+=	freetds/lib/*

BUILDLINK_TARGETS+=	freetds-buildlink

freetds-buildlink: _BUILDLINK_USE

.endif	# FREETDS_BUILDLINK2_MK
