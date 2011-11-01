# $NetBSD: Makefile,v 1.69 2011/11/01 06:00:35 sbd Exp $
#

DISTNAME=	easytag-2.1
PKGREVISION=	8
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=easytag/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://easytag.sourceforge.net/
COMMENT=	GTK+ tag editor for MP3, Ogg Vorbis files, and others

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		pkg-config xgettext

.include "options.mk"

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.4.1
BUILDLINK_API_DEPENDS.gtk2+=	gtk2+>=2.4.1

.include "../../audio/id3lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
