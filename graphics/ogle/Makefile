# $NetBSD: Makefile,v 1.4 2001/12/26 18:22:33 wiz Exp $

DISTNAME=	ogle-0.8.2
CATEGORIES=	graphics
MASTER_SITES=	http://www.dtek.chalmers.se/groups/dvd/dist/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.dtek.chalmers.se/groups/dvd/
COMMENT=	DVD player with menus

DEPENDS+=	jpeg-6b:../../graphics/jpeg
DEPENDS+=	liba52>=0.7.1.2:../../audio/liba52
DEPENDS+=	libdvdread>=0.9.2:../../misc/libdvdread
BUILD_DEPENDS+=	automake>=1.4:../../devel/automake

BUILDLINK_DEPENDS.libxml2=	libxml2>=2.4.5

ONLY_FOR_PLATFORM=	NetBSD-1.5[Y-Z]*-i386 NetBSD-1.[6-9]*-i386

CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}"

GNU_CONFIGURE=		yes
USE_GMAKE=		yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../devel/gettext-lib/buildlink.mk"
.include "../../textproc/libxml2/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
