# $NetBSD: Makefile,v 1.15 1999/10/07 17:41:55 tron Exp $

DISTNAME=	WMMail.app-0.63a
PKGNAME=	wmmail-0.63a
CATEGORIES=	mail x11
MASTER_SITES=	http://www.eecg.utoronto.ca/~chanb/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.eecg.utoronto.ca/~chanb/wmmail.html

DEPENDS+=	windowmaker-*:../../x11/windowmaker

USE_X11BASE=		yes
USE_GMAKE=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-PL-incs="-I${LOCALBASE}/include" \
			--with-PL-libs="-L${LOCALBASE}/lib"

.include "../../mk/bsd.pkg.mk"
