# $NetBSD: Makefile,v 1.6 2004/04/28 05:06:28 snj Exp $

DISTNAME=	Pyrex-0.9
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/P/p/}
CATEGORIES=	lang
MASTER_SITES=	http://www.cosc.canterbury.ac.nz/~greg/python/Pyrex/

MAINTAINER=	tsarna@NetBSD.org
HOMEPAGE=	http://www.cosc.canterbury.ac.nz/~greg/python/Pyrex/
COMMENT=	A Language for Writing Python Extension Modules

PYTHON_VERSIONS_ACCEPTED=	23 23pth 22 22pth

PYDISTUTILSPKG= # defined
USE_BUILDLINK3=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
