# $NetBSD: Makefile,v 1.1.1.1 2004/08/21 15:07:16 darcy Exp $
#

DISTNAME=	generate-2.0
PKGNAME=	${PYPKGPREFIX}-generate-2.0
CATEGORIES=	devel python
MASTER_SITES=	ftp://ftp.druid.net/pub/distrib/
EXTRACT_SUFX=	.tgz

MAINTAINER=	darcy@NetBSD.org
HOMEPAGE=	http://www.druid.net/darcy/readme-generate.html
COMMENT=	Python interface to Generate

MAKE_ENV+=		MANDIR=${LOCALBASE}/man
MAKE_ENV+=		BINDIR=${LOCALBASE}/bin
USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make

PYDISTUTILSPKG=	yes
PYBINMODULE=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
