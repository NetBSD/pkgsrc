# $NetBSD: Makefile,v 1.6 2010/09/23 02:26:46 taca Exp $

DISTNAME=	datamapper-1.0.2
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://datamapper.org/
COMMENT=	Object/Relational Mapper for Ruby
LICENSE=	mit

DEPENDS+= \
  ${RUBY_PKGPREFIX}-dm-core>=1.0.2:../../databases/ruby-dm-core \
  ${RUBY_PKGPREFIX}-dm-aggregates>=1.0.2:../../databases/ruby-dm-aggregates \
  ${RUBY_PKGPREFIX}-dm-constraints>=1.0.2:../../databases/ruby-dm-constraints \
  ${RUBY_PKGPREFIX}-dm-migrations>=1.0.2:../../databases/ruby-dm-migrations \
  ${RUBY_PKGPREFIX}-dm-transactions>=1.0.2:../../databases/ruby-dm-transactions \
  ${RUBY_PKGPREFIX}-dm-serializer>=1.0.2:../../databases/ruby-dm-serializer \
  ${RUBY_PKGPREFIX}-dm-timestamps>=1.0.2:../../databases/ruby-dm-timestamps \
  ${RUBY_PKGPREFIX}-dm-validations>=1.0.2:../../databases/ruby-dm-validations \
  ${RUBY_PKGPREFIX}-dm-types>=1.0.2:../../databases/ruby-dm-types

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
