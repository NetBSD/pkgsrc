# $NetBSD: buildlink3.mk,v 1.4 2020/06/02 08:22:31 adam Exp $

BUILDLINK_TREE+=	glyr

.if !defined(GLYR_BUILDLINK3_MK)
GLYR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.glyr+=	glyr>=1.0.10nb22
BUILDLINK_ABI_DEPENDS.glyr?=	glyr>=1.0.10nb25
BUILDLINK_PKGSRCDIR.glyr?=	../../audio/glyr

.include "../../databases/sqlite3/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.10
.include "../../devel/glib2/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.endif	# GLYR_BUILDLINK3_MK

BUILDLINK_TREE+=	-glyr
