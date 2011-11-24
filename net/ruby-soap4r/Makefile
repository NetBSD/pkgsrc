# $NetBSD: Makefile,v 1.1.1.1 2011/11/24 13:01:13 taca Exp $

DISTNAME=	soap4r-ruby1.9-2.0.3
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/-ruby1.9//}
CATEGORIES=	net

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/noeticpenguin/soap4r-noeticpenguin
COMMENT=	Implementation of SOAP 1.1 for Ruby
LICENSE=	gnu-gpl-v2 OR ruby-license

CONFLICTS+=	ruby[0-9]*-soap4r-*

RUBY_VERSION_SUPPORTED=	19 193

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
