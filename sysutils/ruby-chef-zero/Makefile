# $NetBSD: Makefile,v 1.5 2017/06/06 11:12:05 jperkin Exp $

DISTNAME=	chef-zero-3.2.1
PKGREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/opscode/chef-zero
COMMENT=	Simple fast-start in-memory Chef server
LICENSE=	apache-2.0

DEPENDS+=	${RUBY_PKGPREFIX}-ffi-yajl-[0-9]*:../../devel/ruby-ffi-yajl
DEPENDS+=	${RUBY_PKGPREFIX}-mixlib-log>=1.6.0:../../devel/ruby-mixlib-log
DEPENDS+=	${RUBY_PKGPREFIX}-uuidtools>=2.1:../../devel/ruby-uuidtools
DEPENDS+=	${RUBY_PKGPREFIX}-hashie2>=2.0.5:../../misc/ruby-hashie2
DEPENDS+=	${RUBY_PKGPREFIX}-rack>=1.5.2:../../www/ruby-rack

RUBY_VERSIONS_ACCEPTED=	22 23	# www/ruby-rack

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
