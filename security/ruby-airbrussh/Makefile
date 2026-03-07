# $NetBSD: Makefile,v 1.14 2026/03/07 13:30:46 taca Exp $

DISTNAME=	airbrussh-1.6.1
CATEGORIES=	security

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mattbrictson/airbrussh
COMMENT=	Airbrussh pretties up your SSHKit and Capistrano output
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-sshkit>=1.9.0:../../security/ruby-sshkit

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
