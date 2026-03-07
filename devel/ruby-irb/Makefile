# $NetBSD: Makefile,v 1.8 2026/03/07 13:25:12 taca Exp $

DISTNAME=	irb-1.17.0
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

.if ${RUBY_VER} < 34
DEPENDS+=	${RUBY_PKGPREFIX}-pp>=0.6.0:../../textproc/ruby-pp
.  if ${RUBY_VER} < 33
DEPENDS+=	${RUBY_PKGPREFIX}-reline>=0.4.2:../../devel/ruby-reline
.  endif
.endif

pre-configure:
	${MV} ${WRKSRC}/exe/irb ${WRKSRC}/exe/irb-${PKGVERSION_NOREV}-
	${MV} ${WRKSRC}/man/irb.1 ${WRKSRC}/man/irb-${PKGVERSION_NOREV}-.1

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
