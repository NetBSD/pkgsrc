# $NetBSD: buildlink3.mk,v 1.4 2004/02/04 13:35:51 markd Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
ARTS_BUILDLINK3_MK:=	${ARTS_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	arts
.endif

.if !empty(ARTS_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=		arts
BUILDLINK_DEPENDS.arts+=	arts>=1.1.4nb1
BUILDLINK_PKGSRCDIR.arts?=	../../audio/arts

.  include "../../audio/libaudiofile/buildlink3.mk"
.  include "../../audio/libogg/buildlink3.mk"
.  include "../../audio/libvorbis/buildlink3.mk"
.  include "../../devel/glib2/buildlink2.mk"
.  include "../../mk/ossaudio.buildlink3.mk"
.endif	# ARTS_BUILDLINK3_MK

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
