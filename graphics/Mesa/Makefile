# $NetBSD: Makefile,v 1.41 2001/07/06 00:49:05 fredb Exp $
#

.include "Makefile.common"

DISTNAME=	Mesa-${MESA_VERSION}
PKGNAME=	${DISTNAME}nb1
CATEGORIES=	graphics
MASTER_SITES= 	# empty
DISTFILES=	# empty

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.mesa3d.org/
COMMENT=	Graphics library meta package, similar to SGI's OpenGL


CONFLICTS=	Mesa-glx-*

CHECK_MESA=	yes
.include	"../../mk/bsd.prefs.mk"

.if ${HAVE_BUILTIN_MESA} == "NO"
DEPENDS+=	MesaLib-${MESA_VERSION}:../../graphics/MesaLib
.endif

.if ${HAVE_BUILTIN_GLU} == "NO"
DEPENDS+=	glu-${MESA_VERSION}:../../graphics/glu
.endif

DEPENDS+=	glut-${MESA_VERSION}:../../graphics/glut

USE_X11BASE=	yes
NO_CHECKSUM=	yes
NO_PATCH=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes
EXTRACT_ONLY=	# empty

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
