# $NetBSD: Makefile,v 1.2 2024/09/15 16:46:25 taca Exp $

DISTNAME=	powerbar-2.0.1
CATEGORIES=	misc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/busyloop/powerbar
COMMENT=	The last progressbar-library you'll ever need
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-hashie>=1.1.0:../../misc/ruby-hashie

RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
