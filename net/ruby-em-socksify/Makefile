# $NetBSD: Makefile,v 1.4 2024/07/20 15:30:46 taca Exp $

DISTNAME=	em-socksify-0.3.3
CATEGORIES=	net

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/igrigorik/em-socksify
COMMENT=	Transparent SOCKS support for any EventMachine protocol
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-eventmachine>=1.0.0:../../devel/ruby-eventmachine

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
