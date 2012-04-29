# $NetBSD: Makefile,v 1.2 2012/04/29 14:12:55 taca Exp $

DISTNAME=	domain_name-0.5.3
CATEGORIES=	net

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/knu/ruby-domain_name
COMMENT=	Domain name manipulation library for Ruby
LICENSE=	2-clause-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	${RUBY_PKGPREFIX}-unf>0.0.3:../../converters/ruby-unf

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
