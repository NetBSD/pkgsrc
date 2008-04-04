# $NetBSD: Makefile,v 1.1.1.1 2008/04/04 15:17:43 jlam Exp $

DISTNAME=	logging-0.7.1
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://logging.rubyforge.org/
COMMENT=	Flexible logging library for Ruby based on log4j

DEPENDS+=	${RUBY_PKGPREFIX}-flexmock>=0.8.0:../../devel/ruby-flexmock

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
