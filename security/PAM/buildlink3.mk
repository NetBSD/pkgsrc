# $NetBSD: buildlink3.mk,v 1.25 2009/03/20 19:25:16 joerg Exp $

BUILDLINK_TREE+=	linux-pam

.if !defined(LINUX_PAM_BUILDLINK3_MK)
LINUX_PAM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.linux-pam+=		PAM>=0.75
BUILDLINK_ABI_DEPENDS.linux-pam+=	PAM>=0.77nb5
BUILDLINK_PKGSRCDIR.linux-pam?=		../../security/PAM

.include "../../mk/dlopen.buildlink3.mk"
.endif # LINUX_PAM_BUILDLINK3_MK

BUILDLINK_TREE+=	-linux-pam
