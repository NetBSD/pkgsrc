# $NetBSD: Makefile,v 1.8 2021/03/21 13:28:35 taca Exp $

DISTNAME=	chef-utils-16.11.7
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
