# $NetBSD: Makefile,v 1.25 2004/01/24 13:55:31 grant Exp $

DISTNAME=	WMMail.app-0.64
PKGNAME=	wmmail-0.64
PKGREVISION=	1
CATEGORIES=	mail x11 windowmaker
MASTER_SITES=	http://www.eecg.utoronto.ca/~chanb/WMMail.app/

MAINTAINER=	tron@NetBSD.org
HOMEPAGE=	http://www.eecg.toronto.edu/cgi-bin/cgiwrap/chanb/index.cgi?wmmail
COMMENT=	xbiff like "mail-checker" for WindowMaker

DEPENDS+=	libproplist>=0.10.1:../../devel/libproplist
DEPENDS+=	windowmaker>=0.80.0nb1:../../wm/windowmaker

USE_X11BASE=		yes
USE_GNU_TOOLS+=		make
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-PL-incs="-I${LOCALBASE}/include" \
			--with-PL-libs="-L${LOCALBASE}/lib"

.include "../../mk/bsd.pkg.mk"
