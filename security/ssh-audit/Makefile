# $NetBSD: Makefile,v 1.8 2026/09/22 10:53:09 adam Exp $

DISTNAME=	v3.9.0
PKGNAME=	ssh-audit-3.9.0
CATEGORIES=	security python
# PyPI release doesn't have the manpage.
#MASTER_SITES=	${MASTER_SITE_PYPI:=s/ssh-audit/}
MASTER_SITES=	${MASTER_SITE_GITHUB:=jtesta/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

DIST_SUBDIR=	${PKGNAME_NOREV}
WHEEL_NAME=	${PKGNAME_NOREV:S/-/_/}
WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jtesta/ssh-audit
COMMENT=	Tool for SSH server & client configuration auditing
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_LANGUAGES=	# none

INSTALLATION_DIRS+=	${PKGMANDIR}/man1

post-install:
	${INSTALL_MAN} ${WRKSRC}/ssh-audit.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
