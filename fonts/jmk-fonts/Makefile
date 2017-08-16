# $NetBSD: Makefile,v 1.19 2017/08/16 20:45:36 wiz Exp $
#

DISTNAME=	jmk-x11-fonts-3.0
PKGNAME=	jmk-fonts-3.0
PKGREVISION=	4
CATEGORIES=	fonts x11
MASTER_SITES=	${MASTER_SITE_SUNSITE:=X11/fonts/}

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.jmknoble.net/fonts/
COMMENT=	Jim Knoble's font collection for X11

USE_IMAKE=	yes
MAKE_FLAGS+=	INSTALL_DIR=${PREFIX}/share/fonts/X11/jmk

USE_TOOLS+=	bdftopcf gzip

FONTS_DIRS.x11+=	${PREFIX}/share/fonts/X11/jmk
REQD_DIRS+=		${PREFIX}/share/fonts/X11/jmk

post-install:
	${RM} ${DESTDIR}${PREFIX}/share/fonts/X11/jmk/fonts.scale

.include "../../mk/bsd.pkg.mk"
