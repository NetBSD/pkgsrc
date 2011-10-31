# $NetBSD: Makefile,v 1.28 2011/10/31 11:57:00 obache Exp $
#

DISTNAME=	SOAPpy-0.11.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pywebsvcs/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pywebsvcs.sourceforge.net/
COMMENT=	SOAP implementation

DEPENDS+=	${PYPKGPREFIX}-fpconst>=0.6.0:../../math/py-fpconst
DEPENDS+=	${PYPKGPREFIX}-xml>=0.8.3:../../textproc/py-xml

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
