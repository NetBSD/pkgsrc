# $NetBSD: Makefile,v 1.73 2012/09/07 19:16:07 adam Exp $
#

DISTNAME=	easytag-2.1.7
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=easytag/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://easytag.sourceforge.net/
COMMENT=	GTK+ tag editor for MP3, Ogg Vorbis files, and others
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		pkg-config xgettext

.include "options.mk"

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.4.1
BUILDLINK_API_DEPENDS.gtk2+=	gtk2+>=2.4.1

.include "../../audio/libid3tag/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
