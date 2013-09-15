# $NetBSD: Makefile,v 1.1 2013/09/15 18:46:56 taca Exp $

DISTNAME=	em-socksify-0.3.0
CATEGORIES=	net

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/igrigorik/em-socksify
COMMENT=	Transparent SOCKS support for any EventMachine protocol
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-eventmachine>=1.0.0:../../devel/ruby-eventmachine

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
