# $NetBSD: Makefile,v 1.3 1998/06/22 12:39:46 agc Exp $
# FreeBSD Id: Makefile,v 1.3 1998/04/30 02:38:03 obrien Exp
#

DISTNAME=       sane-0.72
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.mostang.com/pub/sane/

MAINTAINER=	packages@netbsd.org

DEPENDS+=	gtk+-1.0.0:../../x11/gtk

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_X11=	yes

post-install:
	${LDCONFIG} || ${TRUE}

.include "../../mk/bsd.pkg.mk"
