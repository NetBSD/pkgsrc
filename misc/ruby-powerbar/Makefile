# $NetBSD: Makefile,v 1.1 2017/03/17 00:26:52 taca Exp $

DISTNAME=	powerbar-1.0.18
CATEGORIES=	time

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/busyloop/powerbar
COMMENT=	The last progressbar-library you'll ever need
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-hashie>=1.1.0:../../misc/ruby-hashie

RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
