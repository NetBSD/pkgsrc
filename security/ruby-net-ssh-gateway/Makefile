# $NetBSD: Makefile,v 1.1.1.1 2009/12/02 14:35:12 fhajny Exp $

DISTNAME=	net-ssh-gateway-1.0.1
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	net security

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rubyforge.org/projects/net-ssh/
COMMENT=	Simple way to connect to servers behind a firewall or NAT
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-net-ssh>=1.99.1:../../security/ruby-net-ssh

GEM_BUILD=	gemspec

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
