# $NetBSD: Makefile,v 1.6 2011/03/17 22:12:09 zafer Exp $

DISTNAME=	wmnd-0.4.12
PKGREVISION=	1
CATEGORIES=	net x11
MASTER_SITES=	# ftp://ftp.yuv.info/pub/wmnd/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.yuv.info/wmnd/
COMMENT=	Dockable network monitor

PKG_DESTDIR_SUPPORT=	user-destdir

DIST_SUBDIR=	${PKGNAME_NOREV}

GNU_CONFIGURE=	YES

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
