# $NetBSD: Makefile,v 1.35 2003/12/08 14:41:38 wiz Exp $
#

DISTNAME=	easytag-0.30
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=easytag/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://easytag.sourceforge.net/
COMMENT=	Tool to view, edit and write ID3 v1&2 TAGs with a GTK+ interface

DEPENDS+=	gnome1-dirs>=1.0:../../misc/gnome1-dirs
BUILD_USES_MSGFMT=	yes	# xgettext, really

GNU_CONFIGURE=		yes
USE_GMAKE=		yes
USE_X11=		yes
USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../audio/flac/buildlink2.mk"
.include "../../audio/id3lib/buildlink2.mk"
.include "../../audio/libvorbis/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
