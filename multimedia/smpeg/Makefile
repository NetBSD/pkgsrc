# $NetBSD: Makefile,v 1.9 2005/06/14 23:52:03 jlam Exp $
#

DISTNAME=	smpeg-0.4.4
PKGREVISION=	9
CATEGORIES=	devel multimedia
MASTER_SITES=	ftp://sunsite.auc.dk/pub/os/linux/loki/open-source/smpeg/ \
		ftp://ftp.linuxgames.com/loki/open-source/smpeg/

MAINTAINER=	wulf@NetBSD.org
HOMEPAGE=	http://www.lokigames.com/development/smpeg.php3
COMMENT=	SDL MPEG Player Library

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_TOOLS+=	gmake
GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes

.include "../../mk/compiler.mk"

.if !empty(CC_VERSION:MSun)
LIBS.SunOS+=	-lCrun
.endif

CPPFLAGS+=	-Dunix=1

.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"

# smpeg sources (glmovie.c & glmovie-tile.c) assume <malloc.h> exists.
# Create a fake one for platforms that don't have it.
#
post-wrapper:
	if ${TEST} ! -f /usr/include/malloc.h; then			\
		${ECHO} "#include <stdlib.h>"				\
			> ${BUILDLINK_DIR}/include/malloc.h;		\
	fi


.include "../../mk/bsd.pkg.mk"
