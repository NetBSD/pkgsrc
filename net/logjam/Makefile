# $NetBSD: Makefile,v 1.3 2006/12/06 16:31:21 joerg Exp $
#

DISTNAME=	logjam-4.5.3
CATEGORIES=	net
MASTER_SITES=	http://logjam.danga.com/download/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	rillig@NetBSD.org
HOMEPAGE=	http://logjam.danga.com/download/
COMMENT=	GTK client for LiveJournal.com

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-xmms
USE_LIBTOOL=		yes
USE_TOOLS+=		perl pkg-config intltool msgfmt

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/librsvg2/buildlink3.mk"
.include "../../net/libsoup-devel/buildlink3.mk"
.include "../../textproc/gtkspell/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
