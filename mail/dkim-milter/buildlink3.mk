$NetBSD: buildlink3.mk,v 1.1 2009/04/15 03:51:03 manu Exp $

BUILDLINK_TREE+=	dkim-milter

.if !defined(DKIM_MILTER_BUILDLINK3_MK)
DKIM_MILTER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.dkim-milter+=	dkim-milter>=2.8.2
BUILDLINK_PKGSRCDIR.dkim-milter?=	../../mail/dkim-milter
BUILDLINK_DEPMETHOD.dkim-milter?=	build

.include "../../security/openssl/buildlink3.mk"
.include "../../mail/libmilter/buildlink3.mk"
.endif # DKIM_MILTER_BUILDLINK3_MK

BUILDLINK_TREE+=	-dkim-milter
