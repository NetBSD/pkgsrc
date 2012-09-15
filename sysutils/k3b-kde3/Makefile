# $NetBSD: Makefile,v 1.4 2012/09/15 10:06:27 obache Exp $
#

DISTNAME=		k3b-1.0.5
PKGREVISION=		17
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=k3b/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		markd@NetBSD.org
HOMEPAGE=		http://www.k3b.org/
COMMENT=		DVD and CD authoring program

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		cdrdao-[0-9]*:../../sysutils/cdrdao
DEPENDS+=		{cdrtools,cdrtools-ossdvd}-[0-9]*:../../sysutils/cdrtools

GNU_CONFIGURE=		yes
SET_LIBDIR=		yes
USE_TOOLS+=		gmake perl pkg-config
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes

ONLY_FOR_PLATFORM=	FreeBSD-*-* Linux-*-* NetBSD-*-* DragonFly-*-*

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../audio/flac/buildlink3.mk"
.include "../../audio/lame/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../audio/musicbrainz/buildlink3.mk"
.include "../../audio/taglib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/kdebase3/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
