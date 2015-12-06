# $NetBSD: Makefile,v 1.14 2015/12/06 09:21:06 wiz Exp $

DISTNAME=	psutil-release-3.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/-release//}
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=giampaolo/}
GITHUB_PROJECT=	psutil
GITHUB_TAG=	release-${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/giampaolo/psutil
COMMENT=	Cross-platform process and system utilities module for Python
LICENSE=	modified-bsd

REPLACE_PYTHON=	psutil/*py
EGG_NAME=	psutil-${PKGVERSION_NOREV}

.include "../../mk/bsd.prefs.mk"

# facilitate PLIST processing
.if ${OPSYS} == "Darwin"
PLIST_SUBST+=	SYSTEM=osx
.else
PLIST_SUBST+=	SYSTEM=${OPSYS:tl}
.endif

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
