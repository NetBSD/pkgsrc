# $NetBSD: Makefile,v 1.13 2021/04/21 15:35:13 wiz Exp $

DISTNAME=	spider
PKGNAME=	spider-1.1
PKGREVISION=	3
CATEGORIES=	games x11
#MASTER_SITES=	ftp://ftp.uni-koeln.de/windows/xcontrib/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Solitaire card game from xcontrib

USE_IMAKE=	yes
INSTALL_TARGET=	install install.doc install.man

.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
