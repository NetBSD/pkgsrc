# $NetBSD: Makefile,v 1.1.1.1 2001/01/28 19:16:03 ad Exp $
#

DISTNAME=	lopster-0.9.7.2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lopster/}

MAINTAINER=	ad@netbsd.org
HOMEPAGE=	http://lopster.sourceforge.net/

DEPENDS+=	glib>=1.2.0:../../devel/glib
DEPENDS+=	gtk+>=1.2.8:../../x11/gtk

USE_X11BASE=	YES
USE_GMAKE=	YES
GNU_CONFIGURE=	# defined

.include "../../mk/bsd.pkg.mk"
