# $NetBSD: Makefile,v 1.6 2016/10/09 15:24:17 taca Exp $

DISTNAME=	term-ansicolor-1.4.0
CATEGORIES=	devel

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://flori.github.com/term-ansicolor
COMMENT=	Ruby library colors strings using ANSI escape sequences
LICENSE=	gnu-gpl-v2

DEPENDS+=	${RUBY_PKGPREFIX}-tins>=1.0<2:../../devel/ruby-tins

RUBYGEM_OPTIONS+=	--format-executable

pre-configure:
	${CHMOD} +x ${WRKSRC}/bin/*

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
