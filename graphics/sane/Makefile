# $NetBSD: Makefile,v 1.6 1998/08/20 15:17:01 tsarna Exp $
# FreeBSD Id: Makefile,v 1.3 1998/04/30 02:38:03 obrien Exp
#

DISTNAME=       sane-0.74
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.mostang.com/pub/sane/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.mostang.com/sane/

DEPENDS+=	gtk+-1.0.4:../../x11/gtk

CONFLICTS+=	sane-0.72

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_X11=	yes

.include "../../mk/bsd.pkg.mk"
