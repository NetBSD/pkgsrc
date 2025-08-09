# $NetBSD: Makefile,v 1.3 2025/08/09 20:10:23 wiz Exp $

DISTNAME=		getmail6-6.19.08
CATEGORIES=		mail
MASTER_SITES=		${MASTER_SITE_GITHUB:=getmail6/}
GITHUB_TAG=		v${PKGVERSION_NOREV}

MAINTAINER=		sekiya@NetBSD.org
HOMEPAGE=		https://getmail6.org/
COMMENT=		Secure, flexible, reliable fetchmail replacement
LICENSE=		gnu-gpl-v2

TOOL_DEPENDS+=		${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

USE_LANGUAGES=		# none

REPLACE_PYTHON=		*.py getmailcore/*.py

CONFLICTS+=		getmail-[0-9]*
# not yet
#SUPERSEDES=		getmail-[0-9]*

WHEEL_NAME=		${DISTNAME:S/08/8/}

.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
