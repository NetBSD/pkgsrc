# $NetBSD: Makefile,v 1.43.2.1 2002/05/11 02:09:08 jlam Exp $
#

PKGNAME=	Mesa-${MESA_VERSION}
PKGREVISION=	1
MASTER_SITES= 	# empty
DISTFILES=	# empty

MAINTAINER=	packages@netbsd.org
COMMENT=	Graphics library meta package, similar to SGI's OpenGL

CONFLICTS=	Mesa-glx-[0-9]*

.include "Makefile.common"

BUILDLINK_DEPENDS.MesaLib=	MesaLib-${MESA_VERSION}
BUILDLINK_DEPENDS.glu=		glu-${MESA_VERSION}
BUILDLINK_DEPENDS.glut=		glut-${MESA_VERSION}

USE_BUILDLINK2_ONLY=	yes

USE_X11BASE=	yes
NO_CHECKSUM=	yes
NO_PATCH=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes
EXTRACT_ONLY=	# empty

do-install:	# empty

.include "../../graphics/MesaLib/buildlink2.mk"
.include "../../graphics/glu/buildlink2.mk"
.include "../../graphics/glut/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
