# $NetBSD: buildlink3.mk,v 1.2 2022/12/02 15:30:25 jperkin Exp $

BUILDLINK_TREE+=	flite

.if !defined(FLITE_BUILDLINK3_MK)
FLITE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.flite+=	flite>=1.3nb3
BUILDLINK_PKGSRCDIR.flite?=	../../audio/flite

.if ${OPSYS} == "SunOS"
BUILDLINK_LDFLAGS.flite+=	-lsocket -lnsl
.endif
.endif	# FLITE_BUILDLINK3_MK

BUILDLINK_TREE+=	-flite
