# $NetBSD: Makefile,v 1.3 2008/09/15 09:23:04 taca Exp $

DISTNAME=	datamapper-0.9.5
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.datamapper.org/
COMMENT=	Fast, thread-safe, object-relational mapper

DEPENDS+=	${RUBY_PKGPREFIX}-json-pure>=1.1.2:../../textproc/ruby-json-pure
DEPENDS+=	${RUBY_PKGPREFIX}-rspec>=1.1.3:../../devel/ruby-rspec
DEPENDS+=	${RUBY_PKGPREFIX}-validatable>=1.6.7:../../devel/ruby-validatable

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
