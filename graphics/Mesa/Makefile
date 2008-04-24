# $NetBSD: Makefile,v 1.69 2008/04/24 07:40:23 bjs Exp $

PKGNAME=	Mesa-${MESA_PKGVERSION}
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Graphics library meta package, similar to SGI's OpenGL

CONFLICTS=	Mesa-glx-[0-9]*

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		# empty
NO_CHECKSUM=		yes
NO_BUILD=		yes
NO_CONFIGURE=		yes
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
