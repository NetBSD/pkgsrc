# $NetBSD: buildlink3.mk,v 1.1 2007/06/19 01:40:13 rh Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBUPNP_BUILDLINK3_MK:=	${LIBUPNP_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	libupnp
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibupnp}
BUILDLINK_PACKAGES+=	libupnp
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libupnp

.if ${LIBUPNP_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.libupnp+=	libupnp>1.4.6
BUILDLINK_PKGSRCDIR.libupnp?=	../../net/libupnp

PRINT_PLIST_AWK+=	/^@dirrm include\/upnp$$/ { print "@comment in net/libupnp: " $$0; next; }
PRINT_PLIST_AWK+=	/^@exec \$${MKDIR} %D\/include\/upnp$$/ { next; }

.endif	# LIBUPNP_BUILDLINK3_MK

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
