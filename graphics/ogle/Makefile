# $NetBSD: Makefile,v 1.8 2002/06/16 18:12:58 wiz Exp $

DISTNAME=	ogle-0.8.3
CATEGORIES=	graphics
MASTER_SITES=	http://www.dtek.chalmers.se/groups/dvd/dist/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.dtek.chalmers.se/groups/dvd/
COMMENT=	DVD player with menus

DEPENDS+=	liba52>=0.7.3:../../audio/liba52

BUILDLINK_DEPENDS.libxml2=	libxml2>=2.4.19

ONLY_FOR_PLATFORM=	NetBSD-1.5[Y-Z]*-i386 NetBSD-1.[6-9]*-i386

CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}"
#CONFIGURE_ARGS+=--enable-obsdaudio
#CONFIGURE_ARGS+=--disable-sunaudio

GNU_CONFIGURE=		yes
USE_GMAKE=		yes
USE_LIBTOOL=		yes
USE_CONFIG_WRAPPER=	yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../devel/gettext-lib/buildlink.mk"
.include "../../graphics/jpeg/buildlink.mk"
.include "../../misc/libdvdread/buildlink.mk"
.include "../../textproc/libxml2/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
