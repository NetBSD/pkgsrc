# $NetBSD: buildlink3.mk,v 1.20 2009/03/20 19:23:52 joerg Exp $

BUILDLINK_TREE+=	arts

.if !defined(ARTS_BUILDLINK3_MK)
ARTS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.arts+=	arts>=1.1.4nb1
BUILDLINK_ABI_DEPENDS.arts+=	arts>=1.5.8nb1
BUILDLINK_PKGSRCDIR.arts?=	../../audio/arts

PRINT_PLIST_AWK+=	/^@dirrm include\/arts$$/ \
				{ print "@comment in arts: " $$0; next; }

.include "../../audio/libaudiofile/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"

.include "../../mk/oss.buildlink3.mk"

pkgbase := arts
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.arts:Mesound)
.include "../../audio/esound/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.arts:Mnas)
.include "../../audio/nas/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.arts:Mjack)
.include "../../audio/jack/buildlink3.mk"
.endif
.endif # ARTS_BUILDLINK3_MK

BUILDLINK_TREE+=	-arts
