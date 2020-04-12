# $NetBSD: buildlink3.mk,v 1.27 2020/04/12 08:27:59 adam Exp $

BUILDLINK_TREE+=	Pantomime

.if !defined(PANTOMIME_BUILDLINK3_MK)
PANTOMIME_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.Pantomime+=	Pantomime>1.1.9
BUILDLINK_ABI_DEPENDS.Pantomime+=	Pantomime>=1.2.0nb17
BUILDLINK_PKGSRCDIR.Pantomime?=		../../mail/Pantomime

.include "../../devel/gnustep-make/gnustep.mk"

BUILDLINK_INCDIRS.Pantomime+=	lib/GNUstep/Frameworks/Pantomime.framework/Headers
BUILDLINK_FILES.Pantomime+=	include/Pantomime/*.h

.include "../../devel/gnustep-base/buildlink3.mk"
.endif # PANTOMIME_BUILDLINK3_MK

BUILDLINK_TREE+=	-Pantomime
