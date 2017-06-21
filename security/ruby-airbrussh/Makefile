# $NetBSD: Makefile,v 1.4 2017/06/21 14:07:29 taca Exp $

DISTNAME=	airbrussh-1.3.0
CATEGORIES=	security

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mattbrictson/airbrussh
COMMENT=	Airbrussh pretties up your SSHKit and Capistrano output
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-sshkit>=1.9.0:../../security/ruby-sshkit

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
