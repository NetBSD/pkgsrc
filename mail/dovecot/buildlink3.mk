# $NetBSD: buildlink3.mk,v 1.6 2009/12/11 20:52:22 ghen Exp $

.include "../../mk/bsd.fast.prefs.mk"

BUILDLINK_TREE+=	dovecot

.if !defined(DOVECOT_BUILDLINK3_MK)
DOVECOT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.dovecot+=		dovecot>=1.2.0
BUILDLINK_PKGSRCDIR.dovecot?=		../../mail/dovecot

pkgbase := dovecot
.include "../../mk/pkg-build-options.mk"
.endif # DOVECOT_BUILDLINK3_MK

BUILDLINK_TREE+=	-dovecot
