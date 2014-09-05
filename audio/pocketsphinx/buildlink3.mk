# $NetBSD: buildlink3.mk,v 1.1 2014/09/05 10:13:20 fhajny Exp $

BUILDLINK_TREE+=	pocketsphinx

.if !defined(POCKETSPHINX_BUILDLINK3_MK)
POCKETSPHINX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.pocketsphinx+=	pocketsphinx>=0.8
BUILDLINK_ABI_DEPENDS.pocketsphinx+=	pocketsphinx>=0.8
BUILDLINK_PKGSRCDIR.pocketsphinx?=	../../audio/pocketsphinx
BUILDLINK_INCDIRS.pocketsphinx+=	include/pocketsphinx
.endif

BUILDLINK_TREE+=	-pocketsphinx
