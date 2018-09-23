# $NetBSD: Makefile,v 1.2 2018/09/23 13:42:51 taca Exp $

DISTNAME=	mixlib-archive-0.4.16
CATEGORIES=	archivers

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/chef/mixlib-archive
COMMENT=	Simple interface to various archive formats
LICENSE=	apache-2.0

DEPENDS+=	${RUBY_PKGPREFIX}-mixlib-log>=1.6:../../devel/ruby-mixlib-log

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
