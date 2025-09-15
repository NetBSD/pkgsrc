# $NetBSD: Makefile,v 1.14 2025/09/15 15:26:51 taca Exp $

DISTNAME=	term-ansicolor-1.11.3
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/flori/term-ansicolor
COMMENT=	Ruby library colors strings using ANSI escape sequences
LICENSE=	apache-2.0

DEPENDS+=	${RUBY_PKGPREFIX}-tins>=1.0<2:../../devel/ruby-tins

RUBYGEM_OPTIONS+=	--format-executable

pre-configure:
	${CHMOD} +x ${WRKSRC}/bin/*

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
