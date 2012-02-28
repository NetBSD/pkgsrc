# $NetBSD: Makefile,v 1.1.1.1 2012/02/28 20:31:29 minskim Exp $

DISTNAME=	domain_name-0.5.2
CATEGORIES=	net

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/knu/ruby-domain_name
COMMENT=	Domain name manipulation library for Ruby
LICENSE=	2-clause-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	${RUBY_PKGPREFIX}-unf>0.0.3:../../converters/ruby-unf

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
