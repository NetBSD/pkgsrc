# $NetBSD: Makefile,v 1.7 2002/08/04 21:09:23 jdolecek Exp $

DISTNAME=	chkpt-1.7.1
CATEGORIES=	devel
MASTER_SITES=	ftp://gutemine.geo.uni-koeln.de/pub/chkpt/ \
		ftp://ftp.Uni-Koeln.DE/misc/

MAINTAINER=	wennmach@netbsd.org
#HOMEPAGE=
COMMENT=	User-level checkpointing library

ONLY_FOR_PLATFORM=	NetBSD-*

HAS_CONFIGURE=	yes
CONFIGURE_ENV+=	PREFIX="${PREFIX}"

.include "../../mk/bsd.pkg.mk"
