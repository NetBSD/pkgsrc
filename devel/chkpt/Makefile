# $NetBSD: Makefile,v 1.8 2002/08/05 16:43:35 wennmach Exp $

DISTNAME=	chkpt-1.7.1
CATEGORIES=	devel
MASTER_SITES=	ftp://gutemine.geo.uni-koeln.de/pub/chkpt/ \
		ftp://ftp.Uni-Koeln.DE/misc/

MAINTAINER=	wennmach@netbsd.org
#HOMEPAGE=
COMMENT=	User-level checkpointing library

ONLY_FOR_PLATFORM=	NetBSD-1.4*-* NetBSD-1.5-* NetBSD-1.5.*-*

HAS_CONFIGURE=	yes
CONFIGURE_ENV+=	PREFIX="${PREFIX}"

.include "../../mk/bsd.pkg.mk"
