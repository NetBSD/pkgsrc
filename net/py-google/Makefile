# $NetBSD: Makefile,v 1.40 2019/09/02 13:19:52 adam Exp $

DISTNAME=	pygoogle-0.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
PKGREVISION=	5
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pygoogle/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pygoogle.sourceforge.net/
COMMENT=	Call the Google web API from Python

DEPENDS+=	${PYPKGPREFIX}-SOAPpy-[0-9]*:../../net/py-soappy

EGG_NAME=	pygoogle-0.5

PYTHON_VERSIONS_ACCEPTED=	 27 # py-xml via py-soappy

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
