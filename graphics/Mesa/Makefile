# $NetBSD: Makefile,v 1.70 2009/04/08 23:05:45 joerg Exp $

PKGNAME=	Mesa-${MESA_PKGVERSION}
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Graphics library meta package, similar to SGI's OpenGL

META_PACKAGE=	# empty

CONFLICTS=	Mesa-glx-[0-9]*

.include "Makefile.common"

# The ordering is important here as glut/buildlink3.mk sets the version
# of Mesa required.
.include "../../graphics/glut/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
