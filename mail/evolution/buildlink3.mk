# $NetBSD: buildlink3.mk,v 1.24 2009/03/20 19:24:54 joerg Exp $

BUILDLINK_TREE+=	evolution

.if !defined(EVOLUTION_BUILDLINK3_MK)
EVOLUTION_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.evolution+=	evolution>=2.8.0
BUILDLINK_ABI_DEPENDS.evolution?=	evolution>=2.22.3.1nb1
BUILDLINK_PKGSRCDIR.evolution?=	../../mail/evolution

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
.endif # EVOLUTION_BUILDLINK3_MK

BUILDLINK_TREE+=	-evolution
