# $NetBSD: Makefile,v 1.2 2004/11/09 21:32:59 darcy Exp $
#

DISTNAME=	generate-2.1
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.druid.net/pub/distrib/
EXTRACT_SUFX=	.tgz

MAINTAINER=	darcy@NetBSD.org
HOMEPAGE=	http://www.druid.net/darcy/readme-generate.html
COMMENT=	Simple text pre-processor

MAKE_ENV+=		MANDIR=${LOCALBASE}/man
MAKE_ENV+=		BINDIR=${LOCALBASE}/bin

USE_GNU_TOOLS+=	make

.include "../../mk/bsd.pkg.mk"
