# $NetBSD: Makefile,v 1.23 2020/03/20 11:58:13 nia Exp $

DISTNAME=		clusterit-2.5
PKGREVISION=		2
CATEGORIES=		parallel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=clusterit/}

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://clusterit.sourceforge.net/
COMMENT=		Clustering package for unix

GNU_CONFIGURE=		YES

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
