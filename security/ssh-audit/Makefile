# $NetBSD: Makefile,v 1.1 2022/10/29 14:03:09 fcambus Exp $

DISTNAME=	ssh-audit-2.5.0
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=jtesta/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jtesta/ssh-audit/
COMMENT=	Tool for SSH server & client configuration auditing
LICENSE=	mit

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
