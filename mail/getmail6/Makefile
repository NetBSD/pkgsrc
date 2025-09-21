# $NetBSD: Makefile,v 1.6 2025/09/21 21:37:07 wiz Exp $

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

# not yet
#SUPERSEDES=		getmail-[0-9]*

.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
