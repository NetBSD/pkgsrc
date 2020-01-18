# $NetBSD: Makefile,v 1.22 2020/01/18 23:33:24 rillig Exp $

DISTNAME=		clusterit-2.5
PKGREVISION=		2
CATEGORIES=		parallel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=clusterit/}

MAINTAINER=		root@garbled.net
HOMEPAGE=		https://clusterit.sourceforge.net/
COMMENT=		Clustering package for unix

GNU_CONFIGURE=		YES

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
