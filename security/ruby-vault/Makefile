# $NetBSD: Makefile,v 1.4 2023/12/17 15:24:42 taca Exp $

DISTNAME=	vault-0.18.2
CATEGORIES=	security

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/hashicorp/vault-ruby
COMMENT=	Ruby API client for interacting with a Vault server
LICENSE=	mpl-2.0

DEPENDS+=	${RUBY_PKGPREFIX}-aws-sigv4>=0:../../www/ruby-aws-sigv4

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
