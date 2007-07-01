# $NetBSD: Makefile,v 1.15 2007/07/01 16:42:56 heinz Exp $

DISTNAME=	Pyrex-0.9.4.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/P/p/}
CATEGORIES=	lang python
MASTER_SITES=	http://www.cosc.canterbury.ac.nz/greg.ewing/python/Pyrex/

MAINTAINER=	tsarna@NetBSD.org
HOMEPAGE=	http://www.cosc.canterbury.ac.nz/greg.ewing/python/Pyrex/
COMMENT=	Language for Writing Python Extension Modules

PKG_DESTDIR_SUPPORT=		user-destdir

PYTHON_VERSIONS_ACCEPTED=	24 23 22

PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
