# $NetBSD: Makefile,v 1.1.1.1 2008/04/04 15:19:16 jlam Exp $

DISTNAME=	color-1.4.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://color.rubyforge.org/
COMMENT=	Color value conversion and manipulation library

DEPENDS+=	hoe>=1.5.1:../../devel/hoe
DEPENDS+=	${RUBY_PKGPREFIX}-archive-tar-minitar>=0.5.1:../../archivers/ruby-archive-tar-minitar

# Newer version of hoe look for README.txt, not Readme.txt.
SUBST_CLASSES=		readme
SUBST_STAGE.readme=	pre-build
SUBST_FILES.readme=	Manifest.txt Rakefile lib/color.rb
SUBST_SED.readme=	-e "s,Readme,README,g"

post-extract:
	cd ${WRKSRC} && mv Readme.txt README.txt

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
