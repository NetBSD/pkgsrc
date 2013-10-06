# $NetBSD: Makefile,v 1.20 2013/10/06 12:47:13 darcy Exp $
#

DISTNAME=	generate-2.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	http://darcy.druid.net/
EXTRACT_SUFX=	.tgz

OWNER=		darcy@NetBSD.org
HOMEPAGE=	http://www.druid.net/darcy/readme-generate.html
COMMENT=	Python interface to Generate

PYTHON_VERSIONS_INCLUDE_3X=	yes

MAKE_ENV+=		MANDIR=${DESTDIR}${PREFIX}/${PKGMANDIR}
MAKE_ENV+=		BINDIR=${DESTDIR}${PREFIX}/bin
USE_TOOLS+=		gmake

LIBS.SunOS+=	-lnsl -lsocket
LIBS.QNX=		-lsocket

EGG_NAME=	${DISTNAME:S/${PKGVERSION_NOREV}/2.2/}

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
