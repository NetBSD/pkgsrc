# $NetBSD: Makefile,v 1.1.1.1 2001/12/10 20:48:17 veego Exp $

DISTNAME=	ogle-0.8.2
CATEGORIES=	graphics
MASTER_SITES=	http://www.dtek.chalmers.se/groups/dvd/dist/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.dtek.chalmers.se/groups/dvd/index.html
COMMENT=	DVD player with menus

DEPENDS+=	jpeg>=6b:../../graphics/jpeg
DEPENDS+=	liba52>=0.7.1b:../../audio/liba52
DEPENDS+=	libdvdread>=0.9.2:../../misc/libdvdread
BUILD_DEPENDS+=	automake>=1.4:../../devel/automake

BUILDLINK_DEPENDS.libxml2=	libxml2>=2.4.5

CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}"

GNU_CONFIGURE=		yes
USE_GMAKE=		yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../devel/gettext-lib/buildlink.mk"
.include "../../textproc/libxml2/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
