# $NetBSD: Makefile,v 1.20 2009/02/24 16:18:24 wiz Exp $
#

DISTNAME=		gopchop-1.1.7
PKGREVISION=		6
CATEGORIES=		multimedia
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gopchop/} \
			http://outflux.net/unix/software/GOPchop/download/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://outflux.net/unix/software/GOPchop/
COMMENT=		MPEG2 GOP-accurate editor

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_DIRS+=		xdg-1.1
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		intltool msgfmt pkg-config
BROKEN_GETTEXT_DETECTION=	yes

# XXX make this an option?
.include "../../devel/SDL/buildlink3.mk"
#.else
#CONFIGURE_ARGS+=	--disable-sdl

.include "../../multimedia/libmpeg2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
