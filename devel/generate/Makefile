# $NetBSD: Makefile,v 1.17 2009/06/13 06:46:42 rillig Exp $
#

DISTNAME=	generate-2.6
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.druid.net/pub/distrib/
EXTRACT_SUFX=	.tgz

OWNER=		darcy@NetBSD.org
HOMEPAGE=	http://www.druid.net/darcy/readme-generate.html
COMMENT=	Simple text pre-processor

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_ENV+=	${BSD_MAKE_ENV} LIBS=${LIBS:Q}
USE_TOOLS+=	gmake
LIBS.SunOS=	-lsocket -lnsl
LIBS.QNX=	-lsocket

.include "../../mk/bsd.pkg.mk"
