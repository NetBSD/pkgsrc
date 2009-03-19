# $NetBSD: buildlink3.mk,v 1.4 2009/03/19 15:50:27 joerg Exp $

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
BUILDLINK_API_DEPENDS.dovecot+=		dovecot>=1.1beta16
BUILDLINK_PKGSRCDIR.dovecot?=		../../mail/dovecot
.endif # DOVECOT_BUILDLINK3_MK

pkgbase := dovecot
.include "../../mk/pkg-build-options.mk"

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH:S/+$//}
