# $NetBSD: Makefile,v 1.8 1998/11/21 22:56:53 tron Exp $
# FreeBSD Id: Makefile,v 1.3 1998/04/30 02:38:03 obrien Exp
#

DISTNAME=       sane-0.74
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.mostang.com/pub/sane/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.mostang.com/sane/

DEPENDS+=	gtk+-1.0.6:../../x11/gtk10

CONFLICTS+=	sane-0.72

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_X11=	yes

.include "../../mk/bsd.pkg.mk"
