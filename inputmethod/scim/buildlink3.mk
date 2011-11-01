# $NetBSD: buildlink3.mk,v 1.7 2011/11/01 06:01:55 sbd Exp $

BUILDLINK_TREE+=	scim

.if !defined(SCIM_BUILDLINK3_MK)
SCIM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.scim+=	scim>=1.4.7
BUILDLINK_ABI_DEPENDS.scim?=	scim>=1.4.9nb6
BUILDLINK_PKGSRCDIR.scim?=	../../inputmethod/scim

.include "../../devel/gettext-lib/buildlink3.mk"

.if defined(USE_SCIM_GTKUTILS) && !empty(USE_SCIM_GTKUTILS:M[Yy][Ee][Ss])
.  include "../../x11/gtk2/buildlink3.mk"
.endif

.endif # SCIM_BUILDLINK3_MK

BUILDLINK_TREE+=	-scim
