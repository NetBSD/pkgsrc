# $NetBSD: Makefile,v 1.13 2012/07/07 20:33:09 wiz Exp $

DISTNAME=	xournal-0.4.7
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

LDFLAGS.DragonFly=	-lX11 -lz -lm
LDFLAGS.SunOS=		-lX11 -lz -lm

.include "../../graphics/libgnomecanvas/buildlink3.mk"
.include "../../print/poppler-glib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
