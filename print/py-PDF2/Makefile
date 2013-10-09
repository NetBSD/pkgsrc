# $NetBSD: Makefile,v 1.1 2013/10/09 08:53:07 wiz Exp $

DISTNAME=	PyPDF2-1.18
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/Py//}
CATEGORIES=	print python
MASTER_SITES=	https://pypi.python.org/packages/source/P/PyPDF2/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mstamy2.github.io/PyPDF2/
COMMENT=	PDF library for python
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/mstamy2-PyPDF2-4480180

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
