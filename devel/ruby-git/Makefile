# $NetBSD: Makefile,v 1.6 2023/04/08 13:29:13 taca Exp $

DISTNAME=	git-1.18.0
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
