# $NetBSD: buildlink3.mk,v 1.3 2025/09/13 16:16:21 vins Exp $

BUILDLINK_TREE+=	libasr

.if !defined(LIBASR_BUILDLINK3_MK)
LIBASR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libasr+=	libasr>=20250910
BUILDLINK_PKGSRCDIR.libasr?=	../../net/libasr

BUILDLINK_LIBNAME.libasr=	asr
BUILDLINK_LDADD.libasr+=	${BUILDLINK_LIBNAME.libasr:S/^/-l/:S/^-l$//}

.include "../../devel/libevent/buildlink3.mk"
BUILDLINK_LDADD.libasr+=        ${BUILDLINK_LDADD.libevent}

.endif	# LIBASR_BUILDLINK3_MK

BUILDLINK_TREE+=	-libasr
