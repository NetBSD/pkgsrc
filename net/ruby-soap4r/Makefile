# $NetBSD: Makefile,v 1.6 2015/06/08 15:13:02 taca Exp $

DISTNAME=	soap4r-ruby1.9-2.0.5
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/-ruby1.9//}
PKGREVISION=	1
CATEGORIES=	net

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/noeticpenguin/soap4r-noeticpenguin
COMMENT=	Implementation of SOAP 1.1 for Ruby
LICENSE=	gnu-gpl-v2 OR ruby-license

USE_LANGUAGES=	# none

RUBYGEM_OPTIONS+=	--format-executable
OVERRIDE_GEMSPEC= \
	:files lib/soap/rpc/element.rb.orig= lib/xsd/xmlparser.rb.orig=

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
