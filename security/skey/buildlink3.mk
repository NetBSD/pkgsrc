# $NetBSD: buildlink3.mk,v 1.9 2009/03/20 19:25:22 joerg Exp $

BUILDLINK_TREE+=	skey

.if !defined(SKEY_BUILDLINK3_MK)
SKEY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.skey+=	skey>=1.1.5
BUILDLINK_ABI_DEPENDS.skey?=	skey>=1.1.5nb2
BUILDLINK_PKGSRCDIR.skey?=	../../security/skey
BUILDLINK_DEPMETHOD.skey?=	build

.include "../../mk/bsd.fast.prefs.mk"

# PR#40434
.if ${OPSYS} == "SunOS"
BUILDLINK_TRANSFORM+=	l:skey:skey:md5
.endif
.endif # SKEY_BUILDLINK3_MK

BUILDLINK_TREE+=	-skey
