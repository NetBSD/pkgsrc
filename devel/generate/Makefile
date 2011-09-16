# $NetBSD: Makefile,v 1.21 2011/09/16 17:21:46 darcy Exp $
#

DISTNAME=	generate-2.7
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.Vex.Net/pub/distrib/
EXTRACT_SUFX=	.tgz

OWNER=		darcy@NetBSD.org
HOMEPAGE=	http://darcy.druid.net/readme-generate.html
COMMENT=	Simple text pre-processor

PKG_DESTDIR_SUPPORT=	user-destdir

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

MAKE_ENV+=	${BSD_MAKE_ENV} LIBS=${LIBS:Q}
USE_TOOLS+=	gmake
LIBS.SunOS=	-lsocket -lnsl
LIBS.QNX=	-lsocket

.include "../../mk/bsd.pkg.mk"
