# $NetBSD: buildlink3.mk,v 1.1.1.1 2007/09/23 14:55:52 ghen Exp $

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH}+
OPENLDAP_BUILDLINK3_MK:=		${OPENLDAP_BUILDLINK3_MK}+

.include "../../mk/bsd.fast.prefs.mk"

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=			dovecot
.endif

BUILDLINK_PACKAGES:=			${BUILDLINK_PACKAGES:Ndovecot}
BUILDLINK_PACKAGES+=			dovecot
BUILDLINK_ORDER:=			${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}dovecot

.if !empty(OPENLDAP_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.dovecot+=		dovecot>1.0.99
BUILDLINK_PKGSRCDIR.dovecot?=		../../mail/dovecot-devel
.endif

pkgbase := dovecot
.include "../../mk/pkg-build-options.mk"

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH:S/+$//}
