# $NetBSD: Makefile,v 1.23 2006/02/17 19:27:59 wiz Exp $

DISTNAME=	libXg.utf.fonts
PKGNAME=	libXgFonts-1.0
PKGREVISION=	2
CATEGORIES=	fonts plan9
MASTER_SITES=	ftp://ftp.ecf.toronto.edu/pub/plan9/matty/

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	These are the UNICODE fonts for use with 9term and sam

WRKSRC=		${WRKDIR}
NO_BUILD=	yes
USE_X11BASE=	yes

USE_TOOLS+=	bdftopcf
FONTS_DIRS.x11=	${PREFIX}/lib/X11/fonts/Xg
REQD_DIRS=	${PREFIX}/lib/X11/fonts/Xg

.include "../../mk/bsd.pkg.mk"
