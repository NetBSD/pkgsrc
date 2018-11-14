# $NetBSD: Makefile,v 1.83 2018/11/14 22:22:12 kleink Exp $
#

DISTNAME=	logjam-4.5.3
PKGREVISION=	74
CATEGORIES=	net
MASTER_SITES=	http://logjam.danga.com/download/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://logjam.danga.com/download/
COMMENT=	GTK client for LiveJournal.com

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-xmms
USE_LIBTOOL=		yes
USE_TOOLS+=		perl pkg-config intltool msgfmt

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../textproc/gtkspell/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
