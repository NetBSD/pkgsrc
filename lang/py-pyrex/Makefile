# $NetBSD: Makefile,v 1.18 2010/03/15 12:55:46 wiz Exp $

DISTNAME=	Pyrex-0.9.8.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/P/p/}
CATEGORIES=	lang python
MASTER_SITES=	http://www.cosc.canterbury.ac.nz/greg.ewing/python/Pyrex/

MAINTAINER=	tsarna@NetBSD.org
HOMEPAGE=	http://www.cosc.canterbury.ac.nz/greg.ewing/python/Pyrex/
COMMENT=	Language for Writing Python Extension Modules

PKG_DESTDIR_SUPPORT= 	user-destdir

PYDISTUTILSPKG= 	yes
USE_TOOLS+= 	 	pax

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
