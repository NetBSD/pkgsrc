# $NetBSD: Makefile,v 1.6 2009/08/26 19:57:44 sno Exp $
#

DISTNAME=	jpeginfo-1.6.0
PKGREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GENTOO:=distfiles/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.kokkonen.net/tjko/projects.html
COMMENT=	Generates informative listings from JPEG files

GNU_CONFIGURE=	YES

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
