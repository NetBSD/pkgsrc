# $NetBSD: Makefile,v 1.2 2001/02/17 18:22:22 wiz Exp $
#

DISTNAME=	geg-1.0.1
CATEGORIES=	math
MASTER_SITES=	http://www.infolaunch.com/~daveb/

MAINTAINER=	chris@infolaunch.com
HOMEPAGE=	http://www.infolaunch.com/~daveb/
COMMENT=	Program for drawing 2D math functions within a nice GUI

DEPENDS+=	gtk+-1.2.*:../../x11/gtk

GNU_CONFIGURE=	yes

CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}"

.include "../../mk/bsd.pkg.mk"
