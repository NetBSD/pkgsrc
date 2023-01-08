# $NetBSD: Makefile,v 1.3.2.1 2023/01/08 15:57:24 bsiegert Exp $

DISTNAME=	lolcat-100.0.1
PKGREVISION=	3
CATEGORIES=	misc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/busyloop/lolcat
COMMENT=	Rainbows and unicorns!
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-paint>=2.1<3:../../devel/ruby-paint
DEPENDS+=	${RUBY_PKGPREFIX}-optimist>=3.0.0<3.1:../../devel/ruby-optimist

USE_LANGUAGES=	# none

OVERRIDE_GEMSPEC+=	manpages:
RUBYGEM_OPTIONS+=	--format-executable
RUBYGEM_MANPAGES=	yes

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
