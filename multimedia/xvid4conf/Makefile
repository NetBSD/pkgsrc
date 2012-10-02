# $NetBSD: Makefile,v 1.26 2012/10/02 17:11:44 tron Exp $

DISTNAME=	xvid4conf-1.12
PKGREVISION=	16
CATEGORIES=	multimedia
MASTER_SITES=	#

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	XviD Configuration Panel

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	pkg-config
GNU_CONFIGURE=	YES

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
