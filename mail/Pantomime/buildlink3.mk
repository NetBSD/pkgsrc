# $NetBSD: buildlink3.mk,v 1.29 2020/11/05 09:06:58 ryoon Exp $

BUILDLINK_TREE+=	Pantomime

.if !defined(PANTOMIME_BUILDLINK3_MK)
PANTOMIME_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.Pantomime+=	Pantomime>1.1.9
BUILDLINK_ABI_DEPENDS.Pantomime+=	Pantomime>=1.2.0nb19
BUILDLINK_PKGSRCDIR.Pantomime?=		../../mail/Pantomime

.include "../../devel/gnustep-make/gnustep.mk"

BUILDLINK_INCDIRS.Pantomime+=	lib/GNUstep/Frameworks/Pantomime.framework/Headers
BUILDLINK_FILES.Pantomime+=	include/Pantomime/*.h

.include "../../devel/gnustep-base/buildlink3.mk"
.endif # PANTOMIME_BUILDLINK3_MK

BUILDLINK_TREE+=	-Pantomime
