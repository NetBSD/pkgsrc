# $NetBSD: Makefile,v 1.2 2008/08/15 16:05:19 taca Exp $

DISTNAME=	assistance-0.1.5
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rubyforge.org/projects/assistance/
COMMENT=	Lightweight replacement for ActiveSupport

BUILD_DEPENDS+=	${RUBY_PKGPREFIX}-rspec>=1.1.3:../../devel/ruby-rspec

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
