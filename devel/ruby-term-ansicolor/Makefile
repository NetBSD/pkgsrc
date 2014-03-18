# $NetBSD: Makefile,v 1.4 2014/03/18 14:45:25 taca Exp $

DISTNAME=	term-ansicolor-1.3.0
CATEGORIES=	devel

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://flori.github.com/term-ansicolor
COMMENT=	Ruby library colors strings using ANSI escape sequences
LICENSE=	gnu-gpl-v2

DEPENDS+=	${RUBY_PKGPREFIX}-tins>=1.0<2:../../devel/ruby-tins

pre-configure:
	${CHMOD} +x ${WRKSRC}/bin/*

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
