# $NetBSD: Makefile,v 1.16 2022/09/03 04:02:03 taca Exp $

DISTNAME=	digest-3.1.0
CATEGORIES=	security

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ruby/digest
COMMENT=	Provides a framework for message digest libraries
LICENSE=	2-clause-bsd OR ruby-license

# This package is mainly for redmine50 on Ruby 2.7.

# Ruby 3.1 has the same version in it.
RUBY_VERSIONS_ACCEPTED=	27 30

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
