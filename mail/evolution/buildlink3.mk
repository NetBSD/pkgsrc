# $NetBSD: buildlink3.mk,v 1.1 2005/03/22 16:39:39 jmmv Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
EVOLUTION_BUILDLINK3_MK:=	${EVOLUTION_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	evolution
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nevolution}
BUILDLINK_PACKAGES+=	evolution

.if !empty(EVOLUTION_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.evolution+=	evolution>=2.2.0
BUILDLINK_PKGSRCDIR.evolution?=	../../mail/evolution
.endif	# EVOLUTION_BUILDLINK3_MK

PRINT_PLIST_AWK+=	/^@dirrm libexec\/evolution\/2.2$$/ \
				{ print "@comment in evolution: " $$0; next }
PRINT_PLIST_AWK+=	/^@dirrm libexec\/evolution$$/ \
				{ print "@comment in evolution: " $$0; next }

.include "../../devel/gal2/buildlink3.mk"
.include "../../devel/libbonoboui/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../mail/evolution-data-server/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
