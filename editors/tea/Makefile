# $NetBSD: Makefile,v 1.49 2018/11/14 22:21:24 kleink Exp $

DISTNAME=		tea-16.0.5
PKGREVISION=		41
CATEGORIES=		editors
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=tea-editor/}
#https://github.com/psemiletov/tea-qt
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://semiletov.org/tea/
COMMENT=		Powerful, easy-to-use text editor for Gtk2

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config msgfmt
LDFLAGS.DragonFly=	-lX11 -lm
LDFLAGS.SunOS=		-lX11 -lm

.include "options.mk"

.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
