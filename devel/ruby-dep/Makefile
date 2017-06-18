# $NetBSD: Makefile,v 1.3 2017/06/18 13:48:53 taca Exp $

DISTNAME=	ruby_dep-${VERS}
PKGNAME=	${RUBY_PKGPREFIX}-dep-${VERS}
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/e2/ruby_dep
COMMENT=	Extracts supported Ruby versions from Travis file
LICENSE=	mit

VERS=		1.5.0

RUBY_VERSIONS_ACCEPTED= 22 23 24

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
