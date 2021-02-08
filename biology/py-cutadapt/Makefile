# $NetBSD: Makefile,v 1.1 2021/02/08 01:55:23 bacon Exp $

DISTNAME=	cutadapt-3.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cutadapt/}

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://cutadapt.readthedocs.io/en/stable/
COMMENT=	Find and remove adapter sequences, primers, poly-A tails, etc
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-xopen>=1.0.0:../../devel/py-xopen
DEPENDS+=	${PYPKGPREFIX}-dnaio>=0.5.0:../../biology/py-dnaio

PYTHON_SELF_CONFLICT=	yes

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
