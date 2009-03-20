# $NetBSD: buildlink3.mk,v 1.3 2009/03/20 19:23:52 joerg Exp $

BUILDLINK_TREE+=	alsa-lib

.if !defined(ALSA_LIB_BUILDLINK3_MK)
ALSA_LIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.alsa-lib+=	alsa-lib>=1.0.18
BUILDLINK_PKGSRCDIR.alsa-lib?=	../../audio/alsa-lib

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.endif # ALSA_LIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-alsa-lib
