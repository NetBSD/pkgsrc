# $NetBSD: buildlink3.mk,v 1.1 2004/02/27 07:56:33 xtraeme Exp $
#
# This Makefile fragment is included by packages that use devIL.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
DEVIL_BUILDLINK3_MK:=	${DEVIL_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	devIL
.endif

.if !empty(DEVIL_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			devIL
BUILDLINK_DEPENDS.devIL+=		devIL>=1.6.6nb1
BUILDLINK_PKGSRCDIR.devIL?=		../../devel/devIL

.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/libungif/buildlink3.mk"
.include "../../graphics/mng/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../graphics/xpm/buildlink3.mk"

.endif # DEVIL_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
