# $NetBSD: buildlink3.mk,v 1.6 2019/08/30 17:01:33 nia Exp $

BUILDLINK_PREFIX.Mesa=	${BUILDLINK_PREFIX.MesaLib}

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/freeglut/buildlink3.mk"
