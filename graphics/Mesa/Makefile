# $NetBSD: Makefile,v 1.37 2001/02/16 15:22:15 wiz Exp $
#

DISTNAME=	Mesa-3.4
CATEGORIES=	graphics
MASTER_SITES= 	# empty
DISTFILES=	# empty

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.ssec.wisc.edu/~brianp/Mesa.html
COMMENT=	Graphics library meta package, similar to SGI's OpenGL

DEPENDS+=	glu-3.4:../../graphics/glu
DEPENDS+=	glut-3.4:../../graphics/glut

CONFLICTS=	Mesa-glx-*

CHECK_MESA=	yes
.include	"../../mk/bsd.prefs.mk"

.if ${HAVE_BUILTIN_MESA} == "NO"
DEPENDS+=	MesaLib-3.4:../../graphics/MesaLib
.endif

USE_X11BASE=	yes
NO_CHECKSUM=	yes
NO_PATCH=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes
EXTRACT_ONLY=	# empty

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
