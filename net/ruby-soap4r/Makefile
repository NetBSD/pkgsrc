# $NetBSD: Makefile,v 1.5 2014/03/26 13:27:50 taca Exp $

DISTNAME=	soap4r-ruby1.9-2.0.5
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/-ruby1.9//}
CATEGORIES=	net

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/noeticpenguin/soap4r-noeticpenguin
COMMENT=	Implementation of SOAP 1.1 for Ruby
LICENSE=	gnu-gpl-v2 OR ruby-license

CONFLICTS+=	ruby[0-9]*-soap4r-*

RUBY_VERSION_SUPPORTED=	21 200 193
OVERRIDE_GEMSPEC= \
	:files lib/soap/rpc/element.rb.orig= lib/xsd/xmlparser.rb.orig=

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
