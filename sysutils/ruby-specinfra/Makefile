# $NetBSD: Makefile,v 1.33 2026/11/07 14:54:18 taca Exp $

DISTNAME=	specinfra-2.95.2
CATEGORIES=	sysutils

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mizzy/specinfra
COMMENT=	Common layer for serverspec and itamae
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-net-scp>=0:../../security/ruby-net-scp

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
