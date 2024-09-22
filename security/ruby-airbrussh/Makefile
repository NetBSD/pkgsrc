# $NetBSD: Makefile,v 1.12 2024/09/22 06:11:09 taca Exp $

DISTNAME=	airbrussh-1.5.3
CATEGORIES=	security

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mattbrictson/airbrussh
COMMENT=	Airbrussh pretties up your SSHKit and Capistrano output
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-sshkit>=1.9.0:../../security/ruby-sshkit

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
