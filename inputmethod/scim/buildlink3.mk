# $NetBSD: buildlink3.mk,v 1.32 2018/11/14 22:21:52 kleink Exp $

BUILDLINK_TREE+=	scim

.if !defined(SCIM_BUILDLINK3_MK)
SCIM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.scim+=	scim>=1.4.7
BUILDLINK_ABI_DEPENDS.scim+=	scim>=1.4.15nb14
BUILDLINK_PKGSRCDIR.scim?=	../../inputmethod/scim

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"

.if defined(USE_SCIM_GTKUTILS) && !empty(USE_SCIM_GTKUTILS:M[Yy][Ee][Ss])
pkgbase := scim
.include "../../mk/pkg-build-options.mk"
.  if !empty(PKG_BUILD_OPTIONS.scim:Mgtk3)
.include "../../x11/gtk3/buildlink3.mk"
.  else
.include "../../x11/gtk2/buildlink3.mk"
.  endif
.endif

.endif # SCIM_BUILDLINK3_MK

BUILDLINK_TREE+=	-scim
