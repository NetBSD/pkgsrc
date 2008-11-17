# $NetBSD: Makefile,v 1.12 2008/11/17 21:49:49 darcy Exp $
#

DISTNAME=	generate-2.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	ftp://ftp.druid.net/pub/distrib/
EXTRACT_SUFX=	.tgz

MAINTAINER=	darcy@NetBSD.org
HOMEPAGE=	http://www.druid.net/darcy/readme-generate.html
COMMENT=	Python interface to Generate

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_ENV+=		MANDIR=${DESTDIR}${PREFIX}/${PKGMANDIR}
MAKE_ENV+=		BINDIR=${DESTDIR}${PREFIX}/bin
USE_TOOLS+=		gmake

LIBS.SunOS+=	-lnsl -lsocket

PYDISTUTILSPKG=	yes
PYBINMODULE=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
