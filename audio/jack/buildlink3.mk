# $NetBSD: buildlink3.mk,v 1.12 2019/09/09 08:12:09 nia Exp $

BUILDLINK_TREE+=	jack

.if !defined(JACK_BUILDLINK3_MK)
JACK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.jack+=	jack>=0.121.3
BUILDLINK_PKGSRCDIR.jack?=	../../audio/jack

BDB_ACCEPTED=	db4 db5

.include "../../audio/libsamplerate/buildlink3.mk"
.include "../../mk/bdb.buildlink3.mk"
# for DLOPEN_REQUIRE_PTHREADS
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.endif # JACK_BUILDLINK3_MK

BUILDLINK_TREE+=	-jack
