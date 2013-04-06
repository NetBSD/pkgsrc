# $NetBSD: Makefile,v 1.5 2013/04/06 14:09:34 rodent Exp $

DISTNAME=	directory_watcher-1.4.1
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	sysutils

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${MASTER_SITE_RUBYGEMS:=directory_watcher/}
COMMENT=	FAM-like facility for Ruby
LICENSE=	mit

CONFLICTS+=	ruby[1-9][0-9]-directory-watcher-[0-9]*

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
