# $NetBSD: Makefile,v 1.6 2021/02/13 10:19:04 taca Exp $

DISTNAME=	mixlib-archive-1.1.4
CATEGORIES=	archivers

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/chef/mixlib-archive
COMMENT=	Simple interface to various archive formats
LICENSE=	apache-2.0

DEPENDS+=	${RUBY_PKGPREFIX}-mixlib-log>=1.6:../../devel/ruby-mixlib-log

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
