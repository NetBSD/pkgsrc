# $NetBSD: buildlink3.mk,v 1.1 2004/02/11 00:47:04 xtraeme Exp $
#
# This Makefile fragment is included by packages that use cdparanoia.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
CDPARANOIA_BUILDLINK3_MK:=	${CDPARANOIA_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	cdparanoia
.endif

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "FreeBSD" || ${OPSYS} == "NetBSD" || ${OPSYS} == "Linux"
.  if !empty(CDPARANOIA_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			cdparanoia
BUILDLINK_DEPENDS.cdparanoia+=		cdparanoia>=3.0
BUILDLINK_PKGSRCDIR.cdparanoia?=	../../audio/cdparanoia

.  endif # CDPARANOIA_BUILDLINK3_MK
.endif #

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
