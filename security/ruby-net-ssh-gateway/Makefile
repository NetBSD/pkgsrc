# $NetBSD: Makefile,v 1.5 2015/09/26 23:37:45 taca Exp $

DISTNAME=	net-ssh-gateway-1.2.0
CATEGORIES=	net security

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/net-ssh/net-scp
COMMENT=	Simple way to connect to servers behind a firewall or NAT
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-net-ssh>=2.6.5:../../security/ruby-net-ssh

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
