# $NetBSD: buildlink3.mk,v 1.4 2023/08/02 16:24:28 nia Exp $

BUILDLINK_TREE+=	flite

.if !defined(FLITE_BUILDLINK3_MK)
FLITE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.flite+=	flite>=1.3nb3
BUILDLINK_PKGSRCDIR.flite?=	../../audio/flite
BUILDLINK_DEPMETHOD.flite?=	build

.include "../../mk/bsd.fast.prefs.mk"

.if ${OPSYS} == "SunOS"
BUILDLINK_LDFLAGS.flite+=	-lsocket -lnsl
.endif
.endif	# FLITE_BUILDLINK3_MK

BUILDLINK_TREE+=	-flite
