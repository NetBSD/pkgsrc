# $NetBSD: Makefile,v 1.7 2005/01/10 13:40:02 adam Exp $

DISTNAME=	compface-1.5
CATEGORIES=	graphics
MASTER_SITES=	http://freshmeat.net/redir/compface/1439/url_tgz/

MAINTAINER=	oishi@ims.ac.jp
HOMEPAGE=	http://freshmeat.net/projects/compface/
COMMENT=	48x48x1 image compression and decompression (X-face utility)

CONFLICTS=	faces-[0-9]*

USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
GNU_CONFIGURE=		yes

pre-configure:
	cd ${WRKSRC}; ${AUTOCONF}

.include "../../mk/autoconf.mk"
.include "../../mk/bsd.pkg.mk"
