# $NetBSD: Makefile,v 1.21 2005/12/03 17:44:19 joerg Exp $

DISTNAME=	libXg.utf.fonts
PKGNAME=	libXgFonts-1.0
CATEGORIES=	fonts plan9
MASTER_SITES=	ftp://ftp.ecf.toronto.edu/pub/plan9/matty/

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	These are the UNICODE fonts for use with 9term and sam

WRKSRC=		${WRKDIR}
NO_BUILD=	yes
USE_X11BASE=	yes

USE_TOOLS+=	bdftopcf

.include "../../mk/bsd.pkg.mk"
