# $NetBSD: Makefile,v 1.6 2006/02/05 23:08:42 joerg Exp $
#

DISTNAME=	generate-2.2
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.druid.net/pub/distrib/
EXTRACT_SUFX=	.tgz

MAINTAINER=	darcy@NetBSD.org
HOMEPAGE=	http://www.druid.net/darcy/readme-generate.html
COMMENT=	Simple text pre-processor

MAKE_ENV+=	MANDIR=${LOCALBASE}/man
MAKE_ENV+=	BINDIR=${LOCALBASE}/bin

USE_TOOLS+=	gmake

.include "../../mk/bsd.pkg.mk"
