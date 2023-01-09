# $NetBSD: Makefile,v 1.1 2023/01/09 05:30:15 taca Exp $

DISTNAME=	git-1.13.0
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ruby-git/ruby-git
COMMENT=	API to create, read, and manipulate Git repositories
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-addressable>=2.8<3:../../net/ruby-addressable
DEPENDS+=	${RUBY_PKGPREFIX}-rchardet>=1.8<2:../../textproc/ruby-rchardet

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
