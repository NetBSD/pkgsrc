# $NetBSD: Makefile,v 1.10 2008/11/10 17:21:35 wiz Exp $

DISTNAME=	spider
PKGNAME=	spider-1.1
PKGREVISION=	2
CATEGORIES=	games x11
MASTER_SITES=	ftp://ftp.uni-koeln.de/windows/xcontrib/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Solitaire card game from xcontrib

PKG_DESTDIR_SUPPORT=	user-destdir

USE_IMAKE=	yes
INSTALL_TARGET=	install install.doc install.man

.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXp/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
