# $NetBSD: builtin.mk,v 1.1 2008/11/11 16:17:07 cube Exp $

BUILTIN_PKG:=	glut
PKGCONFIG_FILE.glut=	${X11BASE}/lib/pkgconfig/glut.pc

.include "../../mk/buildlink3/pkgconfig-builtin.mk"

.if !empty(USE_BUILTIN.glut:M[Yy][Ee][Ss])

CHECK_BUILTIN.MesaLib:=	yes
CHECK_BUILTIN.glu:=	yes
.  include "../../graphics/MesaLib/builtin.mk"
.  include "../../graphics/glu/builtin.mk"
CHECK_BUILTIN.MesaLib:=	no
CHECK_BUILTIN.glu:=	no

.  if !empty(USE_BUILTIN.MesaLib:M[Nn][Oo]) || \
      !empty(USE_BUILTIN.glu:M[Nn][Oo])
USE_BUILTIN.glut=	no
.  endif

.endif

.include "../../mk/x11.builtin.mk"
