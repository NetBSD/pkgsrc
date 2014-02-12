# $NetBSD: buildlink3.mk,v 1.15 2014/02/12 23:17:35 tron Exp $

BUILDLINK_TREE+=	gale

.if !defined(GALE_BUILDLINK3_MK)
GALE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gale+=	gale>=0.99f
BUILDLINK_ABI_DEPENDS.gale+=	gale>=0.99fnb10
BUILDLINK_PKGSRCDIR.gale?=	../../chat/gale

.include "../../devel/boehm-gc/buildlink3.mk"
.include "../../devel/glib/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../net/adns/buildlink3.mk"
.include "../../security/rsaref/buildlink3.mk"
.include "../../www/libwww/buildlink3.mk"
.endif # GALE_BUILDLINK3_MK

BUILDLINK_TREE+=	-gale
