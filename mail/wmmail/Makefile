# $NetBSD: Makefile,v 1.28 2005/06/01 18:03:00 jlam Exp $

DISTNAME=	WMMail.app-0.64
PKGNAME=	wmmail-0.64
PKGREVISION=	1
CATEGORIES=	mail x11 windowmaker
MASTER_SITES=	http://www.eecg.utoronto.ca/~chanb/WMMail.app/

MAINTAINER=	tron@NetBSD.org
HOMEPAGE=	http://www.eecg.toronto.edu/cgi-bin/cgiwrap/chanb/index.cgi?wmmail
COMMENT=	xbiff like "mail-checker" for WindowMaker

DEPENDS+=	windowmaker>=0.80.0nb1:../../wm/windowmaker

USE_X11BASE=		yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-PL-incs="-I${LOCALBASE}/include" \
			--with-PL-libs="-L${LOCALBASE}/lib"

.include "../../devel/libproplist/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
