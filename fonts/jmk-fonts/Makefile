# $NetBSD: Makefile,v 1.9 2006/02/17 19:34:08 wiz Exp $
#

DISTNAME=	jmk-x11-fonts-3.0
PKGNAME=	jmk-fonts-3.0
PKGREVISION=	2
CATEGORIES=	fonts x11
MASTER_SITES=	${MASTER_SITE_SUNSITE:=X11/fonts/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.ntrnet.net/~jmknoble/fonts/
COMMENT=	Jim Knoble's font collection for X11

USE_IMAKE=	yes
USE_TOOLS+=	bdftopcf

FONTS_DIRS.x11+=	${PREFIX}/lib/X11/fonts/jmk
REQD_DIRS+=		${PREFIX}/lib/X11/fonts/jmk

.include "../../mk/bsd.pkg.mk"
