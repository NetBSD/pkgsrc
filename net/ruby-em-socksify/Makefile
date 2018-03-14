# $NetBSD: Makefile,v 1.3 2018/03/14 15:13:38 taca Exp $

DISTNAME=	em-socksify-0.3.2
CATEGORIES=	net

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/igrigorik/em-socksify
COMMENT=	Transparent SOCKS support for any EventMachine protocol
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-eventmachine>=1.0.0:../../devel/ruby-eventmachine

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
