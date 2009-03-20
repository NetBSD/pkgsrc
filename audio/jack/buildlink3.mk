# $NetBSD: buildlink3.mk,v 1.6 2009/03/20 19:23:54 joerg Exp $

BUILDLINK_TREE+=	jack

.if !defined(JACK_BUILDLINK3_MK)
JACK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.jack+=	jack>=0.110.0
BUILDLINK_PKGSRCDIR.jack?=	../../audio/jack

.include "../../audio/libsamplerate/buildlink3.mk"
# for DLOPEN_REQUIRE_PTHREADS
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.endif # JACK_BUILDLINK3_MK

BUILDLINK_TREE+=	-jack
