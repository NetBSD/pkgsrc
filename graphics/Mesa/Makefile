# $NetBSD: Makefile,v 1.39 2001/04/12 20:38:25 hubertf Exp $
#

.include "Makefile.common"

DISTNAME=	Mesa-${MESA_VERSION}
CATEGORIES=	graphics
MASTER_SITES= 	# empty
DISTFILES=	# empty

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.ssec.wisc.edu/~brianp/Mesa.html
COMMENT=	Graphics library meta package, similar to SGI's OpenGL

DEPENDS+=	glu-${MESA_VERSION}:../../graphics/glu
DEPENDS+=	glut-${MESA_VERSION}:../../graphics/glut

CONFLICTS=	Mesa-glx-*

CHECK_MESA=	yes
.include	"../../mk/bsd.prefs.mk"

.if ${HAVE_BUILTIN_MESA} == "NO"
DEPENDS+=	MesaLib-${MESA_VERSION}:../../graphics/MesaLib
.endif

USE_X11BASE=	yes
NO_CHECKSUM=	yes
NO_PATCH=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes
EXTRACT_ONLY=	# empty

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
