# $NetBSD: Makefile,v 1.1 2025/08/12 12:16:26 ryoon Exp $

DISTNAME=	whirly-0.3.0
CATEGORIES=	devel

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/janlelis/whirly
COMMENT=	Colorful terminal spinner for Ruby
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-unicode-display_width>=1.1:../../textproc/ruby-unicode-display_width

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
