# $NetBSD: Makefile,v 1.3 2011/06/19 03:22:03 taca Exp $

DISTNAME=	directory_watcher-1.4.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	sysutils

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rubygems.org/gems/directory_watcher
COMMENT=	FAM-like facility for Ruby
LICENSE=	mit

CONFLICTS+=	ruby[1-9][0-9]-directory-watcher-[0-9]*

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
