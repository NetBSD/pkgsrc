# $NetBSD: buildlink3.mk,v 1.8 2010/01/17 12:02:14 wiz Exp $

BUILDLINK_TREE+=	ptlib

.if !defined(PTLIB_BUILDLINK3_MK)
PTLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ptlib+=	ptlib>=2.6.1
BUILDLINK_ABI_DEPENDS.ptlib?=	ptlib>=2.6.5nb2
BUILDLINK_PKGSRCDIR.ptlib?=	../../devel/ptlib

.include "../../devel/SDL/buildlink3.mk"
.include "../../databases/openldap-client/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.endif # PTLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-ptlib
