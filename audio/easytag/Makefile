# $NetBSD: Makefile,v 1.40 2004/04/14 16:15:20 jmmv Exp $
#

DISTNAME=	easytag-0.30
PKGREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=easytag/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://easytag.sourceforge.net/
COMMENT=	Tool to view, edit and write ID3 v1&2 TAGs with a GTK+ interface

BUILD_USES_MSGFMT=	yes	# xgettext, really

GNU_CONFIGURE=		yes
USE_DIRS+=		gnome1-1.5
USE_GNU_TOOLS+=		make
USE_X11=		yes
USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes

.include "../../audio/flac/buildlink3.mk"
.include "../../audio/id3lib/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
