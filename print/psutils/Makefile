# $NetBSD: Makefile,v 1.55 2023/06/01 16:18:38 wiz Exp $

DISTNAME=	psutils-3.0.3
CATEGORIES=	print

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rrthomas/psutils/
COMMENT=	Utilities for manipulating PostScript documents (compatibility package)
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-pypspdfutils-[0-9]*:../../print/py-pspdfutils

META_PACKAGE=	yes

.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
