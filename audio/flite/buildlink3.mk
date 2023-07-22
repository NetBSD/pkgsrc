# $NetBSD: buildlink3.mk,v 1.3 2023/07/22 09:32:28 nia Exp $

BUILDLINK_TREE+=	flite

.if !defined(FLITE_BUILDLINK3_MK)
FLITE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.flite+=	flite>=1.3nb3
BUILDLINK_PKGSRCDIR.flite?=	../../audio/flite

.include "../../mk/bsd.fast.prefs.mk"

.if ${OPSYS} == "SunOS"
BUILDLINK_LDFLAGS.flite+=	-lsocket -lnsl
.endif
.endif	# FLITE_BUILDLINK3_MK

BUILDLINK_TREE+=	-flite
