# $NetBSD: Makefile,v 1.1 2020/11/01 20:54:11 joerg Exp $

DISTNAME=	IMAPClient-2.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	mail python
MASTER_SITES=	${MASTER_SITE_GITHUB:=mjs/}
GITHUB_PROJECT=	imapclient
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mjs/imapclient/
COMMENT=	Convience IMAP client for Python
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
