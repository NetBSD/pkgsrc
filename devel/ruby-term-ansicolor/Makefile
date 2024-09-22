# $NetBSD: Makefile,v 1.13 2024/09/22 14:46:33 taca Exp $

DISTNAME=	term-ansicolor-1.11.2
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
