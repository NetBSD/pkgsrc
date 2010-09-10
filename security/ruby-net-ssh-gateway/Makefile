# $NetBSD: Makefile,v 1.2 2010/09/10 07:45:12 taca Exp $

DISTNAME=	net-ssh-gateway-1.0.1
CATEGORIES=	net security

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rubyforge.org/projects/net-ssh/
COMMENT=	Simple way to connect to servers behind a firewall or NAT
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-net-ssh>=1.99.1:../../security/ruby-net-ssh

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
