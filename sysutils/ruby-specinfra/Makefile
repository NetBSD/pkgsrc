# $NetBSD: Makefile,v 1.29 2025/05/18 03:59:22 taca Exp $

DISTNAME=	specinfra-2.94.0
CATEGORIES=	sysutils

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mizzy/specinfra
COMMENT=	Common layer for serverspec and itamae
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-net-scp>=0:../../security/ruby-net-scp

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
