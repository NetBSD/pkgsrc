# $NetBSD: Makefile,v 1.3 2007/04/27 19:57:53 minskim Exp $

DISTNAME=	gem_plugin-0.2.2
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	misc
MASTER_SITES=	http://rubyforge.org/frs/download.php/16607/
EXTRACT_SUFX=	.gem

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://mongrel.rubyforge.org/
COMMENT=	Gem-based plugin system

BROKEN_IN=		pkgsrc-2006Q4

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
