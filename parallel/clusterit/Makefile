# $NetBSD: Makefile,v 1.19 2008/06/07 11:15:59 obache Exp $

DISTNAME=		clusterit-2.5
PKGREVISION=		1
CATEGORIES=		parallel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=clusterit/}

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://clusterit.sourceforge.net/
COMMENT=		Clustering package for unix

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		YES

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
