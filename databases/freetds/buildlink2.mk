# $NetBSD: buildlink2.mk,v 1.2 2002/08/25 19:22:06 jlam Exp $

.if !defined(FREETDS_BUILDLINK2_MK)
FREETDS_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		freetds
BUILDLINK_DEPENDS.freetds?=	freetds>=0.53
BUILDLINK_PKGSRCDIR.freetds?=	../../databases/freetds

EVAL_PREFIX+=			BUILDLINK_PREFIX.freetds=freetds
BUILDLINK_PREFIX.freetds_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.freetds=	freetds/include/*
BUILDLINK_FILES.freetds+=	freetds/lib/*

BUILDLINK_TARGETS+=	freetds-buildlink

freetds-buildlink: _BUILDLINK_USE

.endif	# FREETDS_BUILDLINK2_MK
