# $NetBSD: Makefile,v 1.2 2015/10/04 13:11:08 taca Exp $

DISTNAME=	em-socksify-0.3.1
CATEGORIES=	net

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/igrigorik/em-socksify
COMMENT=	Transparent SOCKS support for any EventMachine protocol
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-eventmachine>=1.0.0:../../devel/ruby-eventmachine

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
