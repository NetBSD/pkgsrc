# $NetBSD: buildlink3.mk,v 1.3 2004/11/20 16:00:35 uebayasi Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
EB_BUILDLINK3_MK:=	${EB_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	eb
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Neb}
BUILDLINK_PACKAGES+=	eb

# XXX We need something generic.
.include "../../mk/bsd.prefs.mk"
PKG_SYSCONFDIR.eb!=	${PKG_INFO} -B eb | \
			sed -ne '/^PKG_SYSCONFDIR/ { s/^PKG_SYSCONFDIR=//; p; }'

.if !empty(EB_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.eb+=		eb>=3.3.2nb1
BUILDLINK_RECOMMENDED.eb+=	eb>=3.3.4nb1
BUILDLINK_PKGSRCDIR.eb?=	../../textproc/eb
.endif	# EB_BUILDLINK3_MK

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
