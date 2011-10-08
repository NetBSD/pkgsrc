# $NetBSD: Makefile,v 1.15 2011/10/08 03:23:38 ryoon Exp $
#

DISTNAME=	jmk-x11-fonts-3.0
PKGNAME=	jmk-fonts-3.0
PKGREVISION=	3
CATEGORIES=	fonts x11
MASTER_SITES=	${MASTER_SITE_SUNSITE:=X11/fonts/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.jmknoble.net/fonts/
COMMENT=	Jim Knoble's font collection for X11

PKG_DESTDIR_SUPPORT=	user-destdir

USE_IMAKE=	yes
MAKE_FLAGS+=	INSTALL_DIR=${PREFIX}/lib/X11/fonts/jmk

USE_TOOLS+=	bdftopcf gzip

USE_X11BASE=		yes
FONTS_DIRS.x11+=	${PREFIX}/lib/X11/fonts/jmk
REQD_DIRS+=		${PREFIX}/lib/X11/fonts/jmk

post-install:
	${RM} ${DESTDIR}${PREFIX}/lib/X11/fonts/jmk/fonts.scale

.include "../../mk/bsd.pkg.mk"
