# $NetBSD: buildlink3.mk,v 1.12 2016/02/26 09:41:06 jperkin Exp $

BUILDLINK_TREE+=	skey

.if !defined(SKEY_BUILDLINK3_MK)
SKEY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.skey+=	skey>=1.1.5
BUILDLINK_ABI_DEPENDS.skey+=	skey>=1.1.5nb2
BUILDLINK_PKGSRCDIR.skey?=	../../security/skey
BUILDLINK_DEPMETHOD.skey?=	build

.include "../../mk/bsd.fast.prefs.mk"

# PR#40434
BUILDLINK_TRANSFORM.SunOS+=	l:skey:skey:md5
# PR#44324
BUILDLINK_TRANSFORM.DragonFly+=	l:skey:skey:md
BUILDLINK_TRANSFORM.FreeBSD+=	l:skey:skey:md
.endif # SKEY_BUILDLINK3_MK

BUILDLINK_TREE+=	-skey
