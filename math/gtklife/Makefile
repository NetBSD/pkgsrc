# $NetBSD: Makefile,v 1.14 2010/09/14 11:02:21 wiz Exp $

DISTNAME=	gtklife-5.1
PKGREVISION=	3
CATEGORIES=	math
MASTER_SITES=	http://ironphoenix.org/tril/gtklife/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ironphoenix.org/tril/gtklife/
COMMENT=	The game of life

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-gtk2
CONFIGURE_ARGS+=--with-docdir=${PREFIX}/share/doc/gtklife
USE_TOOLS+=	gmake pkg-config

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
