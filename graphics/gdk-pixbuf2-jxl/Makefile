# $NetBSD: Makefile,v 1.2 2025/08/30 22:45:20 wiz Exp $

PKGREVISION= 1
.include "../../graphics/libjxl/Makefile.common"

PKGNAME=	${DISTNAME:S/lib/gdk-pixbuf2-/g}
COMMENT=	JpegXL module for GdkPixbuf

WRKSRC=		${WRKDIR}/${DISTNAME}

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

USE_CMAKE=	yes

CONFIGURE_DIRS=	plugins/gdk-pixbuf
BUILD_DIRS=	plugins/gdk-pixbuf

REPLACE_BASH=	deps.sh

SUBST_CLASSES+=		gpt
SUBST_STAGE.gpt=	pre-configure
SUBST_MESSAGE.gpt=	Fixing path to gdk-pixbuf-thumbnailer
SUBST_FILES.gpt=	plugins/gdk-pixbuf/jxl.thumbnailer
SUBST_SED.gpt=		-e 's,/usr,${PREFIX},g'

.include "../../databases/shared-mime-info/mimedb.mk"
.include "../../graphics/gdk-pixbuf2/loaders.mk"
.include "../../graphics/libjxl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
