# $NetBSD: buildlink3.mk,v 1.6 2004/02/08 16:22:37 tron Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
ARTS_BUILDLINK3_MK:=	${ARTS_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	arts
.endif

.if !empty(ARTS_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=		arts
BUILDLINK_DEPENDS.arts+=	arts>=1.1.4nb1
BUILDLINK_PKGSRCDIR.arts?=	../../audio/arts

.  include "../../audio/esound/buildlink3.mk"
.  include "../../audio/libaudiofile/buildlink3.mk"
.  include "../../audio/libmad/buildlink3.mk"
.  include "../../audio/libogg/buildlink3.mk"
.  include "../../audio/libvorbis/buildlink3.mk"
.  include "../../devel/glib2/buildlink3.mk"
.  include "../../mk/ossaudio.buildlink3.mk"
.endif	# ARTS_BUILDLINK3_MK

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
