# $NetBSD: Makefile,v 1.12 2005/12/05 23:55:15 rillig Exp $

DISTNAME=		clusterit-2.3.1
CATEGORIES=		parallel
MASTER_SITES=		http://www.garbled.net/download/

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.garbled.net/clusterit.html
COMMENT=		Clustering package for unix

HAS_CONFIGURE=		YES
CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}

.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
