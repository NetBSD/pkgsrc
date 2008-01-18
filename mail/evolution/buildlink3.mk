# $NetBSD: buildlink3.mk,v 1.21 2008/01/18 05:08:23 tnn Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
EVOLUTION_BUILDLINK3_MK:=	${EVOLUTION_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	evolution
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nevolution}
BUILDLINK_PACKAGES+=	evolution
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}evolution

.if !empty(EVOLUTION_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.evolution+=	evolution>=2.8.0
BUILDLINK_ABI_DEPENDS.evolution?=	evolution>=2.12.3nb1
BUILDLINK_PKGSRCDIR.evolution?=	../../mail/evolution
.endif	# EVOLUTION_BUILDLINK3_MK

PRINT_PLIST_AWK+=	/^@dirrm lib\/evolution\/2.10$$/ \
				{ print "@comment in evolution: " $$0; next }
PRINT_PLIST_AWK+=	/^@dirrm lib\/evolution$$/ \
				{ print "@comment in evolution: " $$0; next }
PRINT_PLIST_AWK+=	/^@dirrm libexec\/evolution\/2.10$$/ \
				{ print "@comment in evolution: " $$0; next }
PRINT_PLIST_AWK+=	/^@dirrm libexec\/evolution$$/ \
				{ print "@comment in evolution: " $$0; next }

.include "../../devel/libbonoboui/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/nspr/buildlink3.mk"
.include "../../devel/nss/buildlink3.mk"
.include "../../mail/evolution-data-server/buildlink3.mk"
.include "../../www/gtkhtml314/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
