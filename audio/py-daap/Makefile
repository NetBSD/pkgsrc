# $NetBSD: Makefile,v 1.20 2024/04/17 10:38:33 wiz Exp $

DISTNAME=	PythonDaap-0.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/PythonD/d/}
PKGREVISION=	3
CATEGORIES=	audio python
MASTER_SITES=	http://jerakeen.org/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://movieos.org/code/pythondaap/
COMMENT=	Python binding for DAAP
LICENSE=	gnu-lgpl-v2.1

PYTHON_VERSIONS_ACCEPTED=	27 # not yet ported as of 0.7

CONFLICTS=	py[0-9]*-PythonDaap-[0-9]*

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
