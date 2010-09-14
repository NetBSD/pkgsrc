# $NetBSD: Makefile,v 1.17 2010/09/14 11:02:32 wiz Exp $

DISTNAME=	xvid4conf-1.12
PKGREVISION=	7
CATEGORIES=	multimedia
MASTER_SITES=	#

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	XviD Configuration Panel

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	pkg-config
GNU_CONFIGURE=	YES

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
