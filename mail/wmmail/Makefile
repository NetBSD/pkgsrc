# $NetBSD: Makefile,v 1.17 2000/10/15 21:54:54 tron Exp $

DISTNAME=	WMMail.app-0.64
PKGNAME=	wmmail-0.64
CATEGORIES=	mail x11
MASTER_SITES=	http://www.eecg.utoronto.ca/~chanb/WMMail.app/

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.eecg.toronto.edu/cgi-bin/cgiwrap/chanb/index.cgi?wmmail

DEPENDS+=	windowmaker-*:../../x11/windowmaker

USE_X11BASE=		yes
USE_GMAKE=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-PL-incs="-I${LOCALBASE}/include" \
			--with-PL-libs="-L${LOCALBASE}/lib"

.include "../../mk/bsd.pkg.mk"
