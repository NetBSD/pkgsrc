# $NetBSD: Makefile,v 1.4 2013/02/11 02:08:16 taca Exp $

DISTNAME=	net-ssh-gateway-1.2.0
CATEGORIES=	net security

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rubyforge.org/projects/net-ssh/
COMMENT=	Simple way to connect to servers behind a firewall or NAT
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-net-ssh>=2.6.5:../../security/ruby-net-ssh

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
