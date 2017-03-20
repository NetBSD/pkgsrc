# $NetBSD: Makefile,v 1.2 2017/03/20 15:07:06 taca Exp $

DISTNAME=	airbrussh-1.1.2
CATEGORIES=	security

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mattbrictson/airbrussh
COMMENT=	Airbrussh pretties up your SSHKit and Capistrano output
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-sshkit>=1.9.0:../../security/ruby-sshkit

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
