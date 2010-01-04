# $NetBSD: Makefile,v 1.13 2010/01/04 17:02:56 joerg Exp $

DISTNAME=	gqview-1.2.2
PKGREVISION=	5
CATEGORIES=	graphics x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gqview/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gqview.sourceforge.net/
COMMENT=	GTK1-based graphic file viewer

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_TOOLS+=		msgfmt
USE_PKGLOCALEDIR=	yes

MAKE_ENV+=		builddir=.

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/gdk-pixbuf/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
