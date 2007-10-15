# $NetBSD: buildlink3.mk,v 1.2 2007/10/15 12:46:09 ghen Exp $

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH}+
DOVECOT_BUILDLINK3_MK:=			${DOVECOT_BUILDLINK3_MK}+

.include "../../mk/bsd.fast.prefs.mk"

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=			dovecot
.endif

BUILDLINK_PACKAGES:=			${BUILDLINK_PACKAGES:Ndovecot}
BUILDLINK_PACKAGES+=			dovecot
BUILDLINK_ORDER:=			${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}dovecot

.if !empty(DOVECOT_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.dovecot+=		dovecot>=1.0.3nb1
BUILDLINK_PKGSRCDIR.dovecot?=		../../mail/dovecot
.endif

pkgbase := dovecot
.include "../../mk/pkg-build-options.mk"

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH:S/+$//}
