# $NetBSD: Makefile,v 1.2 2009/12/08 14:39:14 taca Exp $

DISTNAME=	net-scp-1.0.2
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	net security
DIST_SUBDIR=	ruby-net-scp-20091203

MAINTAINER=	filip@joyent.com
HOMEPAGE=	http://rubyforge.org/projects/net-ssh/
COMMENT=	Secure copy for Ruby
LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	${RUBY_PKGPREFIX}-net-ssh>=1.99.1:../../security/ruby-net-ssh

GEM_BUILD=	gemspec

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
