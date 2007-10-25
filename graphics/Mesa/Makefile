# $NetBSD: Makefile,v 1.68 2007/10/25 22:00:45 jlam Exp $

PKGNAME=	Mesa-${MESA_VERSION}
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Graphics library meta package, similar to SGI's OpenGL

CONFLICTS=	Mesa-glx-[0-9]*

USE_LANGUAGES=		# empty
NO_CHECKSUM=		yes
NO_CONFIGURE=		yes
NO_BUILD=		yes
EXTRACT_ONLY=		# empty
PLIST_SRC=		# empty (meta-package)

do-patch:	# empty
do-install:	# empty

.include "Makefile.common"

# The ordering is important here as glut/buildlink3.mk sets the version
# of Mesa required.
.include "../../graphics/glut/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
