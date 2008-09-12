# $NetBSD: Makefile,v 1.2 2008/09/12 05:32:37 epg Exp $
#

DISTNAME=	Babel-0.9.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	devel python
MASTER_SITES=	http://ftp.edgewall.com/pub/babel/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://babel.edgewall.org/
COMMENT=	Collection of tools for internationalizing Python applications

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
