# $NetBSD: Makefile,v 1.3 2005/11/03 05:12:42 taca Exp $

DISTNAME=	rubygems-0.8.11
PKGREVISION=	1
CATEGORIES=	misc ruby
MASTER_SITES=	http://rubyforge.org/frs/download.php/5207/
EXTRACT_SUFX=	.tgz

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://rubygems.rubyforge.org/
COMMENT=	Ruby standard for publishing and managing third party libraries

RUBY_REQD=	1.8.3

USE_RUBY_SETUP=	yes
REPLACE_RUBY_DIRS=	${WRKSRC}/bin
REPLACE_FILE_PAT=	*

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
