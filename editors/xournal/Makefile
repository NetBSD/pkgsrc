# $NetBSD: Makefile,v 1.6 2011/11/01 06:01:08 sbd Exp $

DISTNAME=	xournal-0.4.5
PKGREVISION=	4
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xournal/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xournal.sourceforge.net/
COMMENT=	Take notes, sketch and annotate PDFs
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c
USE_TOOLS+=	pkg-config msgfmt

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../graphics/libgnomecanvas/buildlink3.mk"
.include "../../print/poppler-glib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
