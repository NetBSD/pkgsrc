# $NetBSD: buildlink3.mk,v 1.2 2023/08/14 05:23:48 wiz Exp $

BUILDLINK_TREE+=	pocketsphinx

.if !defined(POCKETSPHINX_BUILDLINK3_MK)
POCKETSPHINX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.pocketsphinx+=	pocketsphinx>=0.8
BUILDLINK_ABI_DEPENDS.pocketsphinx+=	pocketsphinx>=0.8nb8
BUILDLINK_PKGSRCDIR.pocketsphinx?=	../../audio/pocketsphinx
BUILDLINK_INCDIRS.pocketsphinx+=	include/pocketsphinx
.endif

BUILDLINK_TREE+=	-pocketsphinx
