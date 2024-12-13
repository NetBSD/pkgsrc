# $NetBSD: Makefile,v 1.2 2024/12/13 16:21:24 taca Exp $

DISTNAME=	irb-1.14.2
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ruby/irb
COMMENT=	Interactive Ruby command-line tool
LICENSE=	2-clause-bsd OR ruby-license

USE_LANGUAGES=	# none

RUBYGEM_MANPAGES=	yes

RUBYGEM_OPTIONS+=	--format-executable

#
# Do not install irb command it conflict with ruby (base) package.
#
OVERRIDE_GEMSPEC+=	:executables irb=irb-${PKGVERSION_NOREV}- \
			:files exe/irb=exe/irb-${PKGVERSION_NOREV}- \
			:files man/irb.1=man/irb-${PKGVERSION_NOREV}-.1
FILES_SUBST+=		PKGVERSION_NOREV=${PKGVERSION_NOREV}
PLIST_SUBST+=		PKGVERSION_NOREV=${PKGVERSION_NOREV}

.include "../../lang/ruby/rubyversion.mk"
.if ${RUBY_VER} < 33
DEPENDS+=	${RUBY_PKGPREFIX}-reline>=0.4.2:../../devel/ruby-reline
.endif

pre-configure:
	${MV} ${WRKSRC}/exe/irb ${WRKSRC}/exe/irb-${PKGVERSION_NOREV}-
	${MV} ${WRKSRC}/man/irb.1 ${WRKSRC}/man/irb-${PKGVERSION_NOREV}-.1

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
