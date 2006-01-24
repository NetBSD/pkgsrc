# $NetBSD: buildlink3.mk,v 1.7 2006/01/24 07:32:19 wiz Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
EVOLUTION_BUILDLINK3_MK:=	${EVOLUTION_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	evolution
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nevolution}
BUILDLINK_PACKAGES+=	evolution

.if !empty(EVOLUTION_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.evolution+=	evolution>=2.4.1nb3
BUILDLINK_RECOMMENDED.evolution?=	evolution>=2.4.1nb5
BUILDLINK_PKGSRCDIR.evolution?=	../../mail/evolution
.endif	# EVOLUTION_BUILDLINK3_MK

PRINT_PLIST_AWK+=	/^@dirrm lib\/evolution\/2.4$$/ \
				{ print "@comment in evolution: " $$0; next }
PRINT_PLIST_AWK+=	/^@dirrm lib\/evolution$$/ \
				{ print "@comment in evolution: " $$0; next }
PRINT_PLIST_AWK+=	/^@dirrm libexec\/evolution\/2.4$$/ \
				{ print "@comment in evolution: " $$0; next }
PRINT_PLIST_AWK+=	/^@dirrm libexec\/evolution$$/ \
				{ print "@comment in evolution: " $$0; next }

.include "../../devel/libbonoboui/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/nspr/buildlink3.mk"
.include "../../devel/nss/buildlink3.mk"
.include "../../mail/evolution-data-server/buildlink3.mk"
.include "../../www/gtkhtml38/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
