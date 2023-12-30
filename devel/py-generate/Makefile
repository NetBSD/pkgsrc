# $NetBSD: Makefile,v 1.26 2023/12/30 21:27:19 zafer Exp $

DISTNAME=	generate-2.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	https://darcy.druid.net/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.druid.net/darcy/readme-generate.html
COMMENT=	Python interface to Generate

MAKE_ENV+=		MANDIR=${DESTDIR}${PREFIX}/${PKGMANDIR}
MAKE_ENV+=		BINDIR=${DESTDIR}${PREFIX}/bin
USE_TOOLS+=		gmake

LIBS.SunOS+=	-lnsl -lsocket
LIBS.QNX=	-lsocket

EGG_NAME=	${DISTNAME:S/${PKGVERSION_NOREV}/2.2/}

DIST_SUBDIR=	generate-20151222

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
