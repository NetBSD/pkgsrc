# $NetBSD: buildlink3.mk,v 1.2 2004/04/05 17:00:46 kristerw Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
ALLEGRO_BUILDLINK3_MK:=	${ALLEGRO_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	allegro
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nallegro}
BUILDLINK_PACKAGES+=	allegro

.if !empty(ALLEGRO_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.allegro+=	allegro>=4.1.13
BUILDLINK_PKGSRCDIR.allegro?=	../../devel/allegro
.endif	# ALLEGRO_BUILDLINK3_MK

.include "../../mk/bsd.prefs.mk"

.if !empty(USE_ESOUND:M[Yy][Ee][Ss])
.  include "../../audio/esound/buildlink3.mk"
.endif

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
