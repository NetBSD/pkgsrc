# $NetBSD: Makefile,v 1.58 2023/08/01 23:20:51 wiz Exp $

DISTNAME=	psutils-3.0.3
CATEGORIES=	print

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rrthomas/psutils/
COMMENT=	Utilities for manipulating PostScript documents (compatibility package)
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-pspdfutils-[0-9]*:../../print/py-pspdfutils

META_PACKAGE=	yes

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
