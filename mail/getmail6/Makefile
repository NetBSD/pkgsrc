# $NetBSD: Makefile,v 1.1 2023/10/31 01:54:45 sekiya Exp $

DISTNAME=		getmail6-${GETMAIL6_VERSION}
#PKGREVISION=		1
CATEGORIES=		mail
MASTER_SITES=		${MASTER_SITE_GITHUB:=getmail6/}
GITHUB_TYPE=		tag
GITHUB_TAG=		refs/tags/v${GETMAIL6_VERSION}

GETMAIL6_VERSION=	6.18.13

WRKSRC=			${WRKDIR}/${DISTNAME}

MAINTAINER=		sekiya@NetBSD.org
HOMEPAGE=		https://getmail6.org/
COMMENT=		Secure, flexible, reliable fetchmail replacement
LICENSE=		gnu-gpl-v2

USE_LANGUAGES=		# none

REPLACE_PYTHON=		*.py getmailcore/*.py
PLIST_SUBST+=		GETMAIL6_VERSION="${GETMAIL6_VERSION}"

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
