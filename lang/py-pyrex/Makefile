# $NetBSD: Makefile,v 1.25 2014/01/26 00:30:02 wiz Exp $

DISTNAME=	Pyrex-0.9.9
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/P/p/}
PKGREVISION=	2
CATEGORIES=	lang python
MASTER_SITES=	http://www.cosc.canterbury.ac.nz/greg.ewing/python/Pyrex/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.cosc.canterbury.ac.nz/greg.ewing/python/Pyrex/
COMMENT=	Language for Writing Python Extension Modules
LICENSE=	apache-2.0

USE_TOOLS+= 	 	pax

PYTHON_SELF_CONFLICT=	yes
PYTHON_VERSIONS_INCOMPATIBLE=	33 # not yet ported as of 0.9.9

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
