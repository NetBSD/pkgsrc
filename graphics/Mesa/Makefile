# $NetBSD: Makefile,v 1.57 2004/02/10 23:31:38 jlam Exp $

PKGNAME=	Mesa-${MESA_VERSION}
MASTER_SITES= 	# empty
DISTFILES=	# empty

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Graphics library meta package, similar to SGI's OpenGL

CONFLICTS=	Mesa-glx-[0-9]*

USE_BUILDLINK3=		yes
USE_LANGUAGES=		# empty
NO_CHECKSUM=		yes
NO_CONFIGURE=		yes
NO_BUILD=		yes
NO_PATCH=		yes
EXTRACT_ONLY=		# empty

do-patch:	# empty
do-buildlink:	# empty
do-install:	# empty

.include "Makefile.common"

_MESA_REQD=	${MESA_VERSION}

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/glut/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
