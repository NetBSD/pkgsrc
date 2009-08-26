# $NetBSD: buildlink3.mk,v 1.4 2009/08/26 19:56:54 sno Exp $

BUILDLINK_TREE+=	xulrunner

.if !defined(XULRUNNER_BUILDLINK3_MK)
XULRUNNER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xulrunner+=	xulrunner>=1.9.1nb4
BUILDLINK_ABI_DEPENDS.xulrunner?=	xulrunner>=1.9.1.2nb3
BUILDLINK_PKGSRCDIR.xulrunner?=	../../devel/xulrunner

#.include "../../net/libIDL/buildlink3.mk"
#.include "../../x11/gtk2/buildlink3.mk"
#.include "../../x11/libXt/buildlink3.mk"
.endif # XULRUNNER_BUILDLINK3_MK

BUILDLINK_TREE+=	-xulrunner
