# $NetBSD: buildlink3.mk,v 1.8 2016/02/14 09:45:09 wiz Exp $

BUILDLINK_TREE+=	jack

.if !defined(JACK_BUILDLINK3_MK)
JACK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.jack+=	jack>=0.121.3
BUILDLINK_PKGSRCDIR.jack?=	../../audio/jack

.include "../../audio/libsamplerate/buildlink3.mk"
.include "../../devel/libuuid/buildlink3.mk"
# for DLOPEN_REQUIRE_PTHREADS
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.endif # JACK_BUILDLINK3_MK

BUILDLINK_TREE+=	-jack
