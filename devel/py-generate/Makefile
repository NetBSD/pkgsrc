# $NetBSD: Makefile,v 1.8 2006/08/26 13:00:51 darcy Exp $
#

DISTNAME=	generate-2.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	ftp://ftp.druid.net/pub/distrib/
EXTRACT_SUFX=	.tgz

MAINTAINER=	darcy@NetBSD.org
HOMEPAGE=	http://www.druid.net/darcy/readme-generate.html
COMMENT=	Python interface to Generate

MAKE_ENV+=		MANDIR=${LOCALBASE}/man
MAKE_ENV+=		BINDIR=${LOCALBASE}/bin
USE_TOOLS+=		gmake

LIBS.SunOS+=    -lnsl -lsocket

PYDISTUTILSPKG=	yes
PYBINMODULE=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
