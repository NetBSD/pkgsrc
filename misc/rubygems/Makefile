# $NetBSD: Makefile,v 1.1.1.1 2005/04/10 01:01:33 minskim Exp $

DISTNAME=	rubygems-0.8.10
CATEGORIES=	misc ruby
MASTER_SITES=	http://rubyforge.org/frs/download.php/3700/
EXTRACT_SUFX=	.tgz

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://rubygems.rubyforge.org/
COMMENT=	Ruby standard for publishing and managing third party libraries

DEPENDS+=	${RUBY_PKGPREFIX}-digest-[0-9]*:../../security/ruby-digest
DEPENDS+=	${RUBY_PKGPREFIX}-zlib-[0-9]*:../../devel/ruby-zlib

USE_RUBY_SETUP=	yes

REPLACE_RUBY_DIRS=	${WRKSRC}/bin
REPLACE_FILE_PAT=	*

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
