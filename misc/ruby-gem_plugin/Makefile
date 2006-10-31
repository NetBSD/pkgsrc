# $NetBSD: Makefile,v 1.1.1.1 2006/10/31 19:43:02 minskim Exp $

DISTNAME=	gem_plugin-0.2.1
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	misc
MASTER_SITES=	http://rubyforge.org/frs/download.php/9199/
EXTRACT_SUFX=	.gem

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://mongrel.rubyforge.org/
COMMENT=	Gem-based plugin system

CONFLICTS+=	ruby[1-9]*-gem_plugin-[0-9]*
BUILD_DEPENDS+=	rake>=0.7:../../devel/rake
DEPENDS+=	rubygems-[0-9]*:../../misc/rubygems

FIND_PREFIX:=	RAKE_PREFIX=rake
.include "../../mk/find-prefix.mk"

.include "../../lang/ruby/modules.mk"

do-build:
	cd ${WRKSRC} && ${RAKE_PREFIX}/bin/rake package

do-install:
	${GEM} install ${WRKSRC}/pkg/${DISTNAME}.gem -l

.include "../../mk/bsd.pkg.mk"
