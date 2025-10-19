# $NetBSD: Makefile,v 1.7 2025/10/19 21:07:55 jym Exp $

DISTNAME=		getmail6-6.19.10
CATEGORIES=		mail
MASTER_SITES=		${MASTER_SITE_GITHUB:=getmail6/}
GITHUB_TAG=		v${PKGVERSION_NOREV}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://getmail6.org/
COMMENT=		Secure, flexible, reliable fetchmail replacement
LICENSE=		gnu-gpl-v2 AND apache-2.0

TOOL_DEPENDS+=		${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

USE_LANGUAGES=		# none

REPLACE_PYTHON=		*.py getmailcore/*.py

# Original getmail is parked as mail/getmail5
SUPERSEDES=		getmail<=5.16nb4

.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
