# $NetBSD: Makefile,v 1.25 2011/09/14 17:24:13 hans Exp $
#

DISTNAME=	smpeg-0.4.4
PKGREVISION=	15
CATEGORIES=	devel multimedia
MASTER_SITES=	#

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.lokigames.com/development/smpeg.php3
COMMENT=	SDL MPEG Player Library
LICENSE=	gnu-lgpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir
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

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == "i386" && ${OPSYS} != "Darwin"
CONFIGURE_ARGS+=	--enable-mmx
.endif

.if ${OPSYS} == "SunOS"
MAKE_ENV+=	SunOS_LDFLAGS="-shared -mimpure-text"
.endif

.include "options.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
