# $NetBSD: Makefile,v 1.1 2020/05/02 13:34:42 taca Exp $

DISTNAME=	chef-vault-4.0.1
CATEGORIES=	security

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/chef/chef-vault
COMMENT=	Data encryption support for Chef Infra using data bags
LICENSE=	apache-2.0

USE_LANGUAGES=	# none

RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
