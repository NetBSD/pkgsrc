# $NetBSD: buildlink3.mk,v 1.1 2007/10/31 19:52:35 drochner Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
PY_AT_SPI_BUILDLINK3_MK:=	${PY_AT_SPI_BUILDLINK3_MK}+

.include "../../lang/python/pyversion.mk"

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	py-at-spi
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Npy-at-spi}
BUILDLINK_PACKAGES+=	py-at-spi
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}py-at-spi

.if ${PY_AT_SPI_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.py-at-spi+=	${PYPKGPREFIX}-at-spi>=1.20.1
BUILDLINK_PKGSRCDIR.py-at-spi?=		../../devel/py-at-spi
.endif	# PY_AT_SPI_BUILDLINK3_MK

.include "../../devel/at-spi/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
