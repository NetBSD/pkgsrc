# $NetBSD: Makefile,v 1.3 2012/04/08 19:08:59 wiz Exp $

DISTNAME=	uniconvertor-1.1.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics python
MASTER_SITES=	http://uniconvertor.googlecode.com/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sk1project.org/
COMMENT=	Universal vector graphics translator
LICENSE=	gnu-lgpl-v2 AND gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c
PYDISTUTILSPKG=		yes

DEPENDS+=	${PYPKGPREFIX}-sk1libs-[0-9]*:../../graphics/py-sk1libs

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
