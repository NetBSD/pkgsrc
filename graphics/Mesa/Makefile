# $NetBSD: Makefile,v 1.36 2000/12/12 17:22:38 drochner Exp $
#

DISTNAME=	Mesa-3.4
CATEGORIES=	graphics
MASTER_SITES= 	# empty
DISTFILES=	# empty

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.ssec.wisc.edu/~brianp/Mesa.html

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
