# $NetBSD: buildlink3.mk,v 1.5 2004/03/23 05:29:38 jlam Exp $

BUILDLINK_PREFIX.Mesa=	${BUILDLINK_PREFIX.MesaLib}

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/glut/buildlink3.mk"
