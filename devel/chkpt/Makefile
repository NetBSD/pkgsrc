# $NetBSD: Makefile,v 1.9 2003/07/17 21:29:53 grant Exp $

DISTNAME=	chkpt-1.7.1
CATEGORIES=	devel
MASTER_SITES=	ftp://gutemine.geo.uni-koeln.de/pub/chkpt/ \
		ftp://ftp.Uni-Koeln.DE/misc/

MAINTAINER=	wennmach@NetBSD.org
#HOMEPAGE=
COMMENT=	User-level checkpointing library

ONLY_FOR_PLATFORM=	NetBSD-1.4*-* NetBSD-1.5-* NetBSD-1.5.*-*

HAS_CONFIGURE=	yes
CONFIGURE_ENV+=	PREFIX="${PREFIX}"

.include "../../mk/bsd.pkg.mk"
