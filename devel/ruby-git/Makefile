# $NetBSD: Makefile,v 1.3 2023/02/04 09:44:18 taca Exp $

DISTNAME=	git-1.13.2
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
