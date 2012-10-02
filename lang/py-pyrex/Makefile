# $NetBSD: Makefile,v 1.21 2012/10/02 20:11:50 asau Exp $

DISTNAME=	Pyrex-0.9.9
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/P/p/}
CATEGORIES=	lang python
MASTER_SITES=	http://www.cosc.canterbury.ac.nz/greg.ewing/python/Pyrex/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.cosc.canterbury.ac.nz/greg.ewing/python/Pyrex/
COMMENT=	Language for Writing Python Extension Modules
LICENSE=	apache-2.0

PYDISTUTILSPKG= 	yes
USE_TOOLS+= 	 	pax

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
