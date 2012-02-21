# $NetBSD: Makefile,v 1.26 2012/02/21 06:39:54 sbd Exp $

DISTNAME=	libXg.utf.fonts
PKGNAME=	libXgFonts-1.0
PKGREVISION=	3
CATEGORIES=	fonts plan9
MASTER_SITES=	ftp://ftp.ecf.toronto.edu/pub/plan9/matty/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	These are the UNICODE fonts for use with 9term and sam

WRKSRC=		${WRKDIR}
NO_BUILD=	yes
USE_X11BASE=	yes
PKG_DESTDIR_SUPPORT= user-destdir

USE_TOOLS+=	bdftopcf gzip
FONTS_DIRS.x11=	${PREFIX}/lib/X11/fonts/Xg
REQD_DIRS=	${PREFIX}/lib/X11/fonts/Xg

.include "../../mk/bsd.pkg.mk"
