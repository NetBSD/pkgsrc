# $NetBSD: buildlink3.mk,v 1.11 2004/12/10 06:00:52 markd Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
ARTS_BUILDLINK3_MK:=	${ARTS_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	arts
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Narts}
BUILDLINK_PACKAGES+=	arts

.if !empty(ARTS_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.arts+=	arts>=1.1.4nb1
BUILDLINK_RECOMMENDED.arts+=	arts>=1.3.0nb1
BUILDLINK_PKGSRCDIR.arts?=	../../audio/arts

PRINT_PLIST_AWK+=	/^@dirrm include\/arts$$/ \
				{ print "@comment in arts: " $$0; next; }
.endif	# ARTS_BUILDLINK3_MK

.include "../../audio/esound/buildlink3.mk"
.include "../../audio/libaudiofile/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"

.include "../../mk/ossaudio.buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
