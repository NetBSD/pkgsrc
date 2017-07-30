# $NetBSD: Makefile,v 1.2 2017/07/30 22:32:12 wiz Exp $

DISTNAME=	dm-ferret-adapter-1.2.0
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/datamapper/dm-ferret-adapter
COMMENT=	DataMapper plugin for Ferret
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-dm-core>=1.2.0<1.3:../../databases/ruby-dm-core
DEPENDS+=	${RUBY_PKGPREFIX}-ferret>=0.11.6<0.12:../../textproc/ruby-ferret

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
