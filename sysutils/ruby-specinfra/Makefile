# $NetBSD: Makefile,v 1.6 2020/03/24 18:19:54 taca Exp $

DISTNAME=	specinfra-2.82.12
CATEGORIES=	sysutils

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mizzy/specinfra
COMMENT=	Common layer for serverspec and itamae
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-net-scp>=0:../../security/ruby-net-scp

USE_LANGUAGES=	# none

.include "../../lang/ruby/rubyversion.mk"

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
