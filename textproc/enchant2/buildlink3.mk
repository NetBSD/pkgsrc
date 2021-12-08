# $NetBSD: buildlink3.mk,v 1.7 2021/12/08 16:02:41 adam Exp $

BUILDLINK_TREE+=	enchant2

.if !defined(ENCHANT2_BUILDLINK3_MK)
ENCHANT2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.enchant2+=	enchant2>=2
BUILDLINK_ABI_DEPENDS.enchant2+=	enchant2>=2.3.2
BUILDLINK_PKGSRCDIR.enchant2?=		../../textproc/enchant2

GCC_REQD+=	4.8

# Lots of older software looks for enchant.pc instead of enchant-2.pc.
${BUILDLINK_DIR}/lib/pkgconfig/enchant.pc:
	${MKDIR} ${BUILDLINK_DIR}/lib/pkgconfig
	cd ${BUILDLINK_DIR}/lib/pkgconfig && ${LN} -sf enchant-2.pc enchant.pc

.PHONY: buildlink-enchant2-cookie
buildlink-enchant2-cookie: ${BUILDLINK_DIR}/lib/pkgconfig/enchant.pc

# spelling libraries are loaded dynamically and do not need
# to be included here
.include "../../devel/glib2/buildlink3.mk"
.endif # ENCHANT2_BUILDLINK3_MK

BUILDLINK_TREE+=	-enchant2
