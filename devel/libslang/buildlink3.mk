# $NetBSD: buildlink3.mk,v 1.8 2006/02/05 23:08:45 joerg Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBSLANG_BUILDLINK3_MK:=	${LIBSLANG_BUILDLINK3_MK}+

.include "../../mk/bsd.prefs.mk"

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libslang
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibslang}
BUILDLINK_PACKAGES+=	libslang

.if !empty(LIBSLANG_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.libslang+=	libslang>=1.4.9nb1
BUILDLINK_RECOMMENDED.libslang+=	libslang>=1.4.9nb4
BUILDLINK_PKGSRCDIR.libslang?=	../../devel/libslang
.endif	# LIBSLANG_BUILDLINK3_MK

# Debian adds a dependency on ncurses.
.if (${OPSYS} == "Linux") && (${LOWER_VENDOR} == "debian")
.  include "../../devel/ncurses/buildlink3.mk"
.endif

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
