# $NetBSD: Makefile,v 1.17 2006/07/09 06:55:54 dsainty Exp $
#

DISTNAME=	smpeg-0.4.4
PKGREVISION=	13
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

CPPFLAGS+=	-Dunix=1

# smpeg sources (glmovie.c & glmovie-tile.c) assume <malloc.h> exists.
# Create a fake one for platforms that don't have it.
#
post-wrapper:
	if ${TEST} ! -f /usr/include/malloc.h; then			\
		${ECHO} "#include <stdlib.h>"				\
			> ${BUILDLINK_DIR}/include/malloc.h;		\
	fi

.if ${MACHINE_ARCH} == "i386"
CONFIGURE_ARGS+=	--enable-mmx
.endif

.include "options.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
