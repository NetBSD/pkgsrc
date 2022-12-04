# $NetBSD: Makefile,v 1.15 2022/12/04 15:20:04 taca Exp $

DISTNAME=	chef-utils-18.0.185
CATEGORIES=	sysutils

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/chef/chef/tree/master/chef-utils
COMMENT=	Basic utility functions for Core Chef development
LICENSE=	apache-2.0

DEPENDS+=	${RUBY_PKGPREFIX}-concurrent-ruby>=0:../../devel/ruby-concurrent-ruby

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
