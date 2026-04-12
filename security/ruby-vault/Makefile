# $NetBSD: Makefile,v 1.7 2026/04/12 15:02:55 taca Exp $

DISTNAME=	vault-0.20.1
CATEGORIES=	security

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/hashicorp/vault-ruby
COMMENT=	Ruby API client for interacting with a Vault server
LICENSE=	mpl-2.0

DEPENDS+=	${RUBY_PKGPREFIX}-aws-sigv4>=0:../../www/ruby-aws-sigv4
DEPENDS+=	${RUBY_PKGPREFIX}-connection_pool>=2.4<5:../../net/ruby-connection_pool
DEPENDS+=	${RUBY_PKGPREFIX}-net-http-persistent>=4.0.2<5:../../www/ruby-net-http-persistent

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
