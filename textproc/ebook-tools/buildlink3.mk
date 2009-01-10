# $NetBSD: buildlink3.mk,v 1.1.1.1 2009/01/10 22:20:23 wiz Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
EBOOK_TOOLS_BUILDLINK3_MK:=	${EBOOK_TOOLS_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	ebook-tools
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nebook-tools}
BUILDLINK_PACKAGES+=	ebook-tools
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}ebook-tools

.if ${EBOOK_TOOLS_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.ebook-tools+=	ebook-tools>=0.1.1
BUILDLINK_PKGSRCDIR.ebook-tools?=	../../textproc/ebook-tools
.endif	# EBOOK_TOOLS_BUILDLINK3_MK

.include "../../archivers/libzip/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
