# $NetBSD: Makefile,v 1.8 2007/04/27 19:31:08 minskim Exp $

DISTNAME=	rubygems-0.9.2
CATEGORIES=	misc ruby
MASTER_SITES=	http://rubyforge.org/frs/download.php/17190/
EXTRACT_SUFX=	.tgz

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.rubygems.org/
COMMENT=	Ruby standard for publishing and managing third party libraries

RUBY_REQD=	1.8.3

USE_RUBY_SETUP=	yes
REPLACE_RUBY_DIRS=	${WRKSRC}/bin
REPLACE_FILE_PAT=	[a-z]*

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
