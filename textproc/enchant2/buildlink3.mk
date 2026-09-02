# $NetBSD: buildlink3.mk,v 1.10 2026/09/02 19:04:41 wiz Exp $

BUILDLINK_TREE+=	enchant2

.if !defined(ENCHANT2_BUILDLINK3_MK)
ENCHANT2_BUILDLINK3_MK:=

USE_CXX_FEATURES+=			c++11

BUILDLINK_API_DEPENDS.enchant2+=	enchant2>=2
BUILDLINK_ABI_DEPENDS.enchant2+=	enchant2>=2.8.19nb2
BUILDLINK_PKGSRCDIR.enchant2?=		../../textproc/enchant2

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
