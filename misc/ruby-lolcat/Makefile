# $NetBSD: Makefile,v 1.1 2022/11/11 14:12:34 taca Exp $

DISTNAME=	lolcat-100.0.1
CATEGORIES=	misc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/busyloop/lolcat
COMMENT=	Rainbows and unicorns!
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-paint>=2.1<3:../../devel/ruby-paint
DEPENDS+=	${RUBY_PKGPREFIX}-optimist>=3.0.0<3.1:../../devel/ruby-optimist
DEPENDS+=	${RUBY_PKGPREFIX}-manpages>=0.6.1<0.7:../../misc/ruby-manpages

USE_LANGUAGES=	# none

RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
