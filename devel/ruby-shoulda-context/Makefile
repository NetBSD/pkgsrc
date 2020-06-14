# $NetBSD: Makefile,v 1.6 2020/06/14 13:28:37 taca Exp $

DISTNAME=	shoulda-context-2.0.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	devel ruby

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://thoughtbot.com/community/
COMMENT=	Context framework extracted from Shoulda
LICENSE=	mit

USE_LANGUAGES=	# none

RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
