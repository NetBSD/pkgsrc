# $NetBSD: Makefile,v 1.23 2012/10/04 00:22:01 cheusov Exp $

DISTNAME=	Pyrex-0.9.9
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/P/p/}
PKGREVISION=	1
CATEGORIES=	lang python
MASTER_SITES=	http://www.cosc.canterbury.ac.nz/greg.ewing/python/Pyrex/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.cosc.canterbury.ac.nz/greg.ewing/python/Pyrex/
COMMENT=	Language for Writing Python Extension Modules
LICENSE=	apache-2.0

PYDISTUTILSPKG= 	yes
USE_TOOLS+= 	 	pax

PYTHON_SELF_CONFLICT=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
