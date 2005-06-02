# $NetBSD: Makefile,v 1.11 2005/06/02 20:48:12 garbled Exp $

DISTNAME=		clusterit-2.3.1
CATEGORIES=		parallel
MASTER_SITES=		http://www.garbled.net/download/

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.garbled.net/clusterit.html
COMMENT=		Clustering package for unix

HAS_CONFIGURE=		YES
CONFIGURE_ARGS+=	--prefix=${PREFIX}

.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
