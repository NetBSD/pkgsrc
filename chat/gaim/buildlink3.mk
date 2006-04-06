# $NetBSD: buildlink3.mk,v 1.10 2006/04/06 06:21:38 reed Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GAIM_BUILDLINK3_MK:=	${GAIM_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gaim
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngaim}
BUILDLINK_PACKAGES+=	gaim

.if !empty(GAIM_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.gaim+=	gaim>=1.1.2
BUILDLINK_ABI_DEPENDS.gaim+=	gaim>=1.5.0nb4
BUILDLINK_PKGSRCDIR.gaim?=	../../chat/gaim

PRINT_PLIST_AWK+=	/^@dirrm lib\/gaim$$/ \
				{ print "@comment in gaim: " $$0; next }
.endif  # GAIM_BUILDLINK3_MK

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
