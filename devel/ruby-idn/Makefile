# $NetBSD: Makefile,v 1.1 2017/12/30 04:34:58 tsutsui Exp $

DISTNAME=	idn-ruby-0.1.0
PKGNAME=        ${RUBY_PKGPREFIX}-${DISTNAME:S/ruby-//}
CATEGORIES=	devel

MAINTAINER=	tsutsui@NetBSD.org
HOMEPAGE=	https://github.com/deepfryed/idn-ruby
COMMENT=	Ruby Bindings for the GNU LibIDN library
LICENSE=	apache-2.0

.include "../../lang/ruby/gem.mk"
.include "../../devel/libidn/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
