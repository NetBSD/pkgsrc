# $NetBSD: buildlink3.mk,v 1.10 2012/05/07 01:53:22 dholland Exp $

BUILDLINK_TREE+=	gnustep-objc-lf2

.if !defined(GNUSTEP_OBJC_LF2_BUILDLINK3_MK)
GNUSTEP_OBJC_LF2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnustep-objc-lf2+=	gnustep-objc-lf2>=2.95.3.88nb3
BUILDLINK_ABI_DEPENDS.gnustep-objc-lf2+=	gnustep-objc-lf2>=2.95.3.88nb3
BUILDLINK_PKGSRCDIR.gnustep-objc-lf2?=	../../devel/gnustep-objc-lf2
BUILDLINK_FNAME_TRANSFORM.gnustep-objc-lf2?=	-e "s|include/objc_lf2/|include/objc/|g"
BUILDLINK_TRANSFORM+=	l:objc:objc_lf2

.include "../../devel/gnustep-make/buildlink3.mk"
.endif # GNUSTEP_OBJC_LF2_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnustep-objc-lf2
