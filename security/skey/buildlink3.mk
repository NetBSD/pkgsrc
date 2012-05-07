# $NetBSD: buildlink3.mk,v 1.11 2012/05/07 01:53:58 dholland Exp $

BUILDLINK_TREE+=	skey

.if !defined(SKEY_BUILDLINK3_MK)
SKEY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.skey+=	skey>=1.1.5
BUILDLINK_ABI_DEPENDS.skey+=	skey>=1.1.5nb2
BUILDLINK_PKGSRCDIR.skey?=	../../security/skey
BUILDLINK_DEPMETHOD.skey?=	build

.include "../../mk/bsd.fast.prefs.mk"

# PR#40434
.if ${OPSYS} == "SunOS"
BUILDLINK_TRANSFORM+=	l:skey:skey:md5
# PR#44324
.elif ${OPSYS} == "DragonFly" || ${OPSYS} == "FreeBSD"
BUILDLINK_TRANSFORM+=	l:skey:skey:md
.endif
.endif # SKEY_BUILDLINK3_MK

BUILDLINK_TREE+=	-skey
