# $NetBSD: buildlink3.mk,v 1.13 2006/12/12 21:52:35 joerg Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBSLANG_BUILDLINK3_MK:=	${LIBSLANG_BUILDLINK3_MK}+

.include "../../mk/bsd.fast.prefs.mk"

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libslang
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibslang}
BUILDLINK_PACKAGES+=	libslang
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libslang

.if !empty(LIBSLANG_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.libslang+=	libslang>=1.4.9nb1
BUILDLINK_ABI_DEPENDS.libslang+=	libslang>=1.4.9nb4
BUILDLINK_PKGSRCDIR.libslang?=	../../devel/libslang
.endif	# LIBSLANG_BUILDLINK3_MK

# Debian adds a dependency on ncurses.
.if (${OPSYS} == "Linux") && (${LOWER_VENDOR} == "debian")
.  include "../../devel/ncurses/buildlink3.mk"
.endif

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
