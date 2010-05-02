# $NetBSD: Makefile,v 1.19 2010/05/02 13:51:44 wiz Exp $

DISTNAME=	Pyrex-0.9.9
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/P/p/}
CATEGORIES=	lang python
MASTER_SITES=	http://www.cosc.canterbury.ac.nz/greg.ewing/python/Pyrex/

MAINTAINER=	tsarna@NetBSD.org
HOMEPAGE=	http://www.cosc.canterbury.ac.nz/greg.ewing/python/Pyrex/
COMMENT=	Language for Writing Python Extension Modules
LICENSE=	apache-2.0

PKG_DESTDIR_SUPPORT= 	user-destdir

PYDISTUTILSPKG= 	yes
USE_TOOLS+= 	 	pax

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
