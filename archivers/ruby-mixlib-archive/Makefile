# $NetBSD: Makefile,v 1.4 2020/01/18 15:06:12 taca Exp $

DISTNAME=	mixlib-archive-1.0.5
CATEGORIES=	archivers

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/chef/mixlib-archive
COMMENT=	Simple interface to various archive formats
LICENSE=	apache-2.0

DEPENDS+=	${RUBY_PKGPREFIX}-mixlib-log>=1.6:../../devel/ruby-mixlib-log

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
