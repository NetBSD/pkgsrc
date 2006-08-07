# $NetBSD: Makefile,v 1.4 2006/08/07 16:12:27 taca Exp $

DISTNAME=	rubygems-0.9.0
CATEGORIES=	misc ruby
MASTER_SITES=	http://rubyforge.org/frs/download.php/11289/
EXTRACT_SUFX=	.tgz

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.rubygems.org/
COMMENT=	Ruby standard for publishing and managing third party libraries

RUBY_REQD=	1.8.3

USE_RUBY_SETUP=	yes
REPLACE_RUBY_DIRS=	${WRKSRC}/bin
REPLACE_FILE_PAT=	*

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
