# $NetBSD: Makefile,v 1.10 1999/01/30 23:18:51 agc Exp $
# FreeBSD Id: Makefile,v 1.3 1998/04/30 02:38:03 obrien Exp
#

DISTNAME=       sane-1.00
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.mostang.com/pub/sane/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.mostang.com/sane/

DEPENDS+=	gtk+-1.0.6:../../x11/gtk10
DEPENDS+=	gimp-1.0.2:../../graphics/gimp

CONFLICTS+=	sane-0.72 sane-0.74

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_X11BASE=	yes

# -O to workaorund bug with -O2 and egcs.
CFLAGS=		-O -I${LOCALBASE}/include

.include "../../mk/bsd.pkg.mk"
