# $NetBSD: Makefile,v 1.4 2003/09/21 09:30:59 jmc Exp $

DISTNAME=	Pyrex-0.8.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/P/p/}
CATEGORIES=	lang
MASTER_SITES=	http://www.cosc.canterbury.ac.nz/~greg/python/Pyrex/

MAINTAINER=	tsarna@NetBSD.org
HOMEPAGE=	http://www.cosc.canterbury.ac.nz/~greg/python/Pyrex/
COMMENT=	A Language for Writing Python Extension Modules

PYTHON_VERSIONS_ACCEPTED=	23 23pth 22 22pth

PYDISTUTILSPKG= # defined
USE_BUILDLINK2=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
