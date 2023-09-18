# $NetBSD: Makefile,v 1.3 2023/09/18 17:35:36 taca Exp $

DISTNAME=	vault-0.18.1
CATEGORIES=	security

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/hashicorp/vault-ruby
COMMENT=	Ruby API client for interacting with a Vault server
LICENSE=	mpl-2.0

DEPENDS+=	${RUBY_PKGPREFIX}-aws-sigv4>=0:../../www/ruby-aws-sigv4

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
