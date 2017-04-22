# $NetBSD: Makefile,v 1.7 2017/04/22 16:32:13 taca Exp $

DISTNAME=	term-ansicolor-1.6.0
CATEGORIES=	devel

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	https://flori.github.com/term-ansicolor
COMMENT=	Ruby library colors strings using ANSI escape sequences
LICENSE=	apache-2.0

DEPENDS+=	${RUBY_PKGPREFIX}-tins>=1.0<2:../../devel/ruby-tins

RUBYGEM_OPTIONS+=	--format-executable

pre-configure:
	${CHMOD} +x ${WRKSRC}/bin/*

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
