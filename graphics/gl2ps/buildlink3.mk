# $NetBSD: buildlink3.mk,v 1.6 2026/11/25 14:42:12 wiz Exp $

BUILDLINK_TREE+=	gl2ps

.if !defined(GL2PS_BUILDLINK3_MK)
GL2PS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gl2ps+=	gl2ps>=1.4.2
BUILDLINK_ABI_DEPENDS.gl2ps+=	gl2ps>=1.4.2nb2
BUILDLINK_PKGSRCDIR.gl2ps?=	../../graphics/gl2ps

.include "../../mk/bsd.fast.prefs.mk"
.if ${OPSYS} != "Darwin"
.include "../../mk/mesa.buildlink3.mk"
.include "../../graphics/freeglut/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.endif
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"

.endif	# GL2PS_BUILDLINK3_MK

BUILDLINK_TREE+=	-gl2ps
