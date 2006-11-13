# $NetBSD: buildlink3.mk,v 1.12 2006/11/13 16:59:22 wulf Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
GNURADIO_CORE_BUILDLINK3_MK:=	${GNURADIO_CORE_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	gnuradio-core
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngnuradio-core}
BUILDLINK_PACKAGES+=	gnuradio-core
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}gnuradio-core

.if ${GNURADIO_CORE_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.gnuradio-core+=	gnuradio-core>=3.0.2
BUILDLINK_PKGSRCDIR.gnuradio-core?=	../../ham/gnuradio-core
BUILDLINK_CPPFLAGS.gnuradio-core+=    -I${BUILDLINK_PREFIX.gnuradio-core}/include/gnuradio
.endif	# GNURADIO_CORE_BUILDLINK3_MK

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/cppunit/buildlink3.mk"
.include "../../devel/swig/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../lang/python/pyversion.mk"
.include "../../math/fftwf/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
