# $NetBSD: Makefile,v 1.1.1.1 2008/04/04 15:20:13 jlam Exp $

DISTNAME=	transaction-simple-1.4.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	misc

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Mixin library for adding transaction support to objects

DEPENDS+=	hoe>=1.5.1:../../devel/hoe

# Newer version of hoe look for README.txt, not Readme.txt.
SUBST_CLASSES=		readme
SUBST_STAGE.readme=	pre-build
SUBST_FILES.readme=	Manifest.txt Rakefile lib/transaction/simple.rb
SUBST_SED.readme=	-e "s,Readme,README,g"

post-extract:
	cd ${WRKSRC} && mv Readme.txt README.txt

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
