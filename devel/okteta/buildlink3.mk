# $NetBSD: buildlink3.mk,v 1.1 2013/11/07 10:42:26 markd Exp $

BUILDLINK_TREE+=	okteta

.if !defined(OKTETA_BUILDLINK3_MK)
OKTETA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.okteta+=	okteta>=4.11.3
BUILDLINK_PKGSRCDIR.okteta?=	../../devel/okteta

#.include "../../security/qca2/buildlink3.mk"
#.include "../../x11/kdelibs4/buildlink3.mk"
.endif	# OKTETA_BUILDLINK3_MK

BUILDLINK_TREE+=	-okteta
