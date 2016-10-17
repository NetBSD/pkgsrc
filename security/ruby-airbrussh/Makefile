# $NetBSD: Makefile,v 1.1 2016/10/17 15:42:35 taca Exp $

DISTNAME=	airbrussh-1.1.1
CATEGORIES=	security

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mattbrictson/airbrussh
COMMENT=	Airbrussh pretties up your SSHKit and Capistrano output
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-sshkit>=1.9.0:../../security/ruby-sshkit

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
