# $NetBSD: buildlink3.mk,v 1.2 2007/09/21 13:03:34 wiz Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
DEVHELP_BUILDLINK3_MK:=	${DEVHELP_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	devhelp
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ndevhelp}
BUILDLINK_PACKAGES+=	devhelp
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}devhelp

.if ${DEVHELP_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.devhelp+=	devhelp>=0.12nb1
BUILDLINK_PKGSRCDIR.devhelp?=	../../devel/devhelp
.endif	# DEVHELP_BUILDLINK3_MK

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/libwnck/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
