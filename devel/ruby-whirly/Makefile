# $NetBSD: Makefile,v 1.2 2026/01/17 16:59:28 taca Exp $

DISTNAME=	whirly-0.4.0
CATEGORIES=	devel

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/janlelis/whirly
COMMENT=	Colorful terminal spinner for Ruby
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-unicode-display_width>=1.1:../../textproc/ruby-unicode-display_width

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
