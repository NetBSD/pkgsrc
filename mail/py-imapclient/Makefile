# $NetBSD: Makefile,v 1.2 2021/02/13 21:46:26 adam Exp $

DISTNAME=	IMAPClient-2.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	mail python
MASTER_SITES=	${MASTER_SITE_PYPI:=I/IMAPClient/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mjs/imapclient
COMMENT=	Convience IMAP client for Python
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
