# $NetBSD: Makefile,v 1.6 2013/06/16 17:15:26 taca Exp $

DISTNAME=	net-scp-1.1.1
CATEGORIES=	net security

MAINTAINER=	filip@joyent.com
HOMEPAGE=	http://rubyforge.org/projects/net-ssh/
COMMENT=	Secure copy for Ruby
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-net-ssh>=2.6.5:../../security/ruby-net-ssh

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
