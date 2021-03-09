# $NetBSD: Makefile,v 1.7 2021/03/09 08:58:23 nia Exp $

DISTNAME=	chef-utils-16.10.17
CATEGORIES=	sysutils

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/chef/chef/tree/master/chef-utils
COMMENT=	Basic utility functions for Core Chef development
LICENSE=	apache-2.0

USE_LANGUAGES=	# none

# "chef-utils requires Ruby version >= 2.6.0."
RUBY_VERSIONS_INCOMPATIBLE=	25

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
