# $NetBSD: buildlink3.mk,v 1.42 2012/09/22 13:48:18 ryoon Exp $

BUILDLINK_TREE+=	kdemultimedia

.if !defined(KDEMULTIMEDIA_BUILDLINK3_MK)
KDEMULTIMEDIA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kdemultimedia+=	kdemultimedia>=3.5.0nb2
BUILDLINK_ABI_DEPENDS.kdemultimedia+=	kdemultimedia>=3.5.10nb21
BUILDLINK_PKGSRCDIR.kdemultimedia?=	../../multimedia/kdemultimedia3

.include "../../audio/arts/buildlink3.mk"
.include "../../audio/lame/buildlink3.mk"
#.include "../../audio/musicbrainz/buildlink3.mk"
#.include "../../audio/libtunepimp/buildlink3.mk"
.include "../../audio/taglib/buildlink3.mk"
.if defined(PTHREAD_TYPE) && ${PTHREAD_TYPE} == "pth"
.include "../../devel/pthread-sem/buildlink3.mk"
.endif
.include "../../multimedia/xine-lib/buildlink3.mk"
.include "../../x11/kdebase3/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.endif # KDEMULTIMEDIA_BUILDLINK3_MK

BUILDLINK_TREE+=	-kdemultimedia
