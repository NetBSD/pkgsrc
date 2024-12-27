# $NetBSD: buildlink3.mk,v 1.108 2024/12/27 08:19:50 wiz Exp $

BUILDLINK_TREE+=	simgear

.if !defined(SIMGEAR_BUILDLINK3_MK)
SIMGEAR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.simgear+=	simgear>=2018.2.2nb7
BUILDLINK_ABI_DEPENDS.simgear?=	simgear>=2020.3.11nb48
BUILDLINK_PKGSRCDIR.simgear?=	../../games/simgear

.include "../../audio/openal-soft/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.fast.prefs.mk"
.if ${OPSYS} != "Darwin"
.  include "../../graphics/MesaLib/buildlink3.mk"
.endif
.include "../../graphics/osg/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.endif	# SIMGEAR_BUILDLINK3_MK

BUILDLINK_TREE+=	-simgear
