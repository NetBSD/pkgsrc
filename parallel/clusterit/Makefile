# $NetBSD: Makefile,v 1.17 2007/02/02 00:34:13 joerg Exp $

DISTNAME=		clusterit-2.4
PKGREVISION=		1
CATEGORIES=		parallel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=clusterit/}

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://clusterit.sourceforge.net/
COMMENT=		Clustering package for unix

GNU_CONFIGURE=		YES

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
