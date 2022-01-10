# $NetBSD: Makefile,v 1.29 2022/01/10 22:11:41 wiz Exp $

DISTNAME=	CDDB-1.4
PKGNAME=	${PYPKGPREFIX}-cddb-1.4
PKGREVISION=	3
CATEGORIES=	audio python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cddb-py/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://cddb-py.sourceforge.net/
COMMENT=	Python module to access the CDDB online database
LICENSE=	gnu-gpl-v2

PYTHON_VERSIONS_ACCEPTED=	27 # not yet ported as of 1.4

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
