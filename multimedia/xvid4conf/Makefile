# $NetBSD: Makefile,v 1.15 2009/08/26 19:58:08 sno Exp $

DISTNAME=	xvid4conf-1.12
PKGREVISION=	5
CATEGORIES=	multimedia
MASTER_SITES=	#

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	XviD Configuration Panel

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	pkg-config
GNU_CONFIGURE=	YES

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
