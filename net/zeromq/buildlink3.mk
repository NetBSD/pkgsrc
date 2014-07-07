# $NetBSD: buildlink3.mk,v 1.4 2014/07/07 13:05:35 obache Exp $
#

BUILDLINK_TREE+=	zeromq

.if !defined(ZEROMQ_BUILDLINK3_MK)
ZEROMQ_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.zeromq+=	zeromq>=2.0.11
BUILDLINK_ABI_DEPENDS.zeromq+=	zeromq>=4.0.4nb1
BUILDLINK_PKGSRCDIR.zeromq?=	../../net/zeromq

.include "../../security/libsodium/buildlink3.mk"

.include "../../mk/bsd.fast.prefs.mk"

.if ${OPSYS} == "Linux" || ${OPSYS} == "SunOS"
.include "../../devel/libuuid/buildlink3.mk"
.endif

.endif	# ZEROMQ_BUILDLINK3_MK

BUILDLINK_TREE+=	-zeromq
