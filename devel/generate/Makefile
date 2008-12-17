# $NetBSD: Makefile,v 1.13 2008/12/17 15:44:10 darcy Exp $
#

DISTNAME=	generate-2.6
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.druid.net/pub/distrib/
EXTRACT_SUFX=	.tgz

MAINTAINER=	darcy@NetBSD.org
HOMEPAGE=	http://www.druid.net/darcy/readme-generate.html
COMMENT=	Simple text pre-processor

MAKE_ENV+=	${BSD_MAKE_ENV} LIBS=${LIBS:Q}
USE_TOOLS+=	gmake
LIBS.SunOS=	-lsocket -lnsl
LIBS.QNX=	-lsocket
CFLAGS.QNX=	-U__STRICT_ANSI__

.include "../../mk/bsd.pkg.mk"
