# $NetBSD: Makefile,v 1.9 2015/02/04 16:11:32 taca Exp $

DISTNAME=	net-scp-1.2.1
CATEGORIES=	net security

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rubyforge.org/projects/net-ssh/
COMMENT=	Secure copy for Ruby
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-net-ssh>=2.6.5:../../security/ruby-net-ssh

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
