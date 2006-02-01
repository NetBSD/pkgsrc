# $NetBSD: Makefile,v 1.14 2006/02/01 19:26:47 garbled Exp $

DISTNAME=		clusterit-2.4
CATEGORIES=		parallel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=clusterit/}

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://clusterit.sourceforge.net/
COMMENT=		Clustering package for unix

HAS_CONFIGURE=		YES
CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}

.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
