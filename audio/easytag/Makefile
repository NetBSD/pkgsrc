# $NetBSD: Makefile,v 1.20 2003/01/03 15:24:57 wiz Exp $
#

DISTNAME=	easytag-0.26
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=easytag/}

MAINTAINER=	wiz@netbsd.org
HOMEPAGE=	http://easytag.sourceforge.net/
COMMENT=	Tool to view, edit and write ID3 v1&2 TAGs with a GTK+ interface

BUILD_USES_MSGFMT=	yes				# xgettext, really

GNU_CONFIGURE=		yes
USE_GMAKE=		yes
USE_X11=		yes
USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

#.include "../../audio/flac/buildlink2.mk"
.include "../../audio/id3lib/buildlink2.mk"
.include "../../audio/libvorbis/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
