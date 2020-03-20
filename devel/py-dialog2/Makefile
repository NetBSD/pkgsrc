# $NetBSD: Makefile,v 1.13 2020/03/20 11:57:30 nia Exp $

DISTNAME=	python2-pythondialog-3.5.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^python2-python//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python2-pythondialog/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pythondialog.sourceforge.net/
COMMENT=	Python wrapper for the dialog utility
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=	# none

PYTHON_VERSIONS_ACCEPTED=	27

.include "../../misc/dialog/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
