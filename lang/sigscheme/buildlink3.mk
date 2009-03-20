# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:24:52 joerg Exp $

BUILDLINK_TREE+=	sigscheme

.if !defined(SIGSCHEME_BUILDLINK3_MK)
SIGSCHEME_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.sigscheme+=	sigscheme>=0.8.0
BUILDLINK_PKGSRCDIR.sigscheme?=	../../lang/sigscheme

.include "../../devel/libgcroots/buildlink3.mk"
.endif # SIGSCHEME_BUILDLINK3_MK

BUILDLINK_TREE+=	-sigscheme
