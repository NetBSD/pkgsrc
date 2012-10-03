# $NetBSD: Makefile,v 1.83.2.1 2012/10/03 12:08:03 spz Exp $

DISTNAME=	gqview-2.0.4
PKGREVISION=	13
CATEGORIES=	graphics x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gqview/}

MAINTAINER=	drochner@NetBSD.org
HOMEPAGE=	http://gqview.sourceforge.net/
COMMENT=	GTK2-based graphic file viewer

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		msgfmt pkg-config
GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
LIBS+=			-lm
LIBS.SunOS+=		-lsocket

MAKE_ENV+=		builddir=.

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
