# $NetBSD: Makefile,v 1.4 2009/05/12 13:27:55 obache Exp $
#

DISTNAME=	Babel-0.9.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	devel python
MASTER_SITES=	http://ftp.edgewall.com/pub/babel/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://babel.edgewall.org/
COMMENT=	Collection of tools for internationalizing Python applications

LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
