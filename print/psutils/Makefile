# $NetBSD: Makefile,v 1.56 2023/06/02 06:19:23 mrg Exp $

DISTNAME=	psutils-3.0.3
CATEGORIES=	print

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rrthomas/psutils/
COMMENT=	Utilities for manipulating PostScript documents (compatibility package)
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-pspdfutils-[0-9]*:../../print/py-pspdfutils

META_PACKAGE=	yes

.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
