# $NetBSD: Makefile,v 1.20 2001/09/27 23:18:23 jlam Exp $

DISTNAME=	WMMail.app-0.64
PKGNAME=	wmmail-0.64
CATEGORIES=	mail x11
MASTER_SITES=	http://www.eecg.utoronto.ca/~chanb/WMMail.app/

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.eecg.toronto.edu/cgi-bin/cgiwrap/chanb/index.cgi?wmmail
COMMENT=	xbiff like "mail-checker" for WindowMaker

DEPENDS+=	windowmaker-[0-9]*:../../wm/windowmaker

USE_X11BASE=		yes
USE_GMAKE=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-PL-incs="-I${LOCALBASE}/include" \
			--with-PL-libs="-L${LOCALBASE}/lib"

.include "../../mk/bsd.pkg.mk"
