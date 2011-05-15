# $NetBSD: Makefile,v 1.3 2011/05/15 19:34:51 gls Exp $

DISTNAME=	net-ssh-gateway-1.1.0
CATEGORIES=	net security

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rubyforge.org/projects/net-ssh/
COMMENT=	Simple way to connect to servers behind a firewall or NAT
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-net-ssh>=1.99.1:../../security/ruby-net-ssh

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
