# $NetBSD: buildlink3.mk,v 1.40 2020/11/05 09:06:56 ryoon Exp $
#

BUILDLINK_TREE+=	input-pad

.if !defined(INPUT_PAD_BUILDLINK3_MK)
INPUT_PAD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.input-pad+=	input-pad>=1.0.2
BUILDLINK_ABI_DEPENDS.input-pad?=	input-pad>=1.0.3nb17
BUILDLINK_PKGSRCDIR.input-pad?=		../../inputmethod/input-pad

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libxkbfile/buildlink3.mk"
.include "../../x11/libxklavier/buildlink3.mk"
.endif	# INPUT_PAD_BUILDLINK3_MK

BUILDLINK_TREE+=	-input-pad
