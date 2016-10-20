# $NetBSD: Makefile,v 1.7 2016/10/20 09:02:42 fhajny Exp $

DISTNAME=	hiera-1.3.4
PKGREVISION=	2
CATEGORIES=	time

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/puppetlabs/hiera/
COMMENT=	Light weight hierarchical data store
LICENSE=	apache-2.0

RUBYGEM_OPTIONS+=	--format-executable
OVERRIDE_GEMSPEC+=	json_pure:json>=1.6.0

.include "../../lang/ruby/json.mk"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
