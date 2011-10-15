# $NetBSD: Makefile,v 1.17 2011/10/15 11:46:04 obache Exp $
#

DISTNAME=	generate-2.6
PKGREVISION=	2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	ftp://ftp.druid.net/pub/distrib/
EXTRACT_SUFX=	.tgz

OWNER=		darcy@NetBSD.org
HOMEPAGE=	http://www.druid.net/darcy/readme-generate.html
COMMENT=	Python interface to Generate

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_ENV+=		MANDIR=${DESTDIR}${PREFIX}/${PKGMANDIR}
MAKE_ENV+=		BINDIR=${DESTDIR}${PREFIX}/bin
USE_TOOLS+=		gmake

LIBS.SunOS+=	-lnsl -lsocket
LIBS.QNX=		-lsocket

EGG_NAME=	${DISTNAME:S/${PKGVERSION_NOREV}/2.2/}

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
