# $NetBSD: Makefile,v 1.6 2004/03/16 02:01:10 taca Exp $
#

DISTNAME=	ri-0.8a
PKGNAME=	${RUBY_PKGNAMEPREFIX}${DISTNAME}
CATEGORIES=	devel ruby
MASTER_SITES=	http://www.pragmaticprogrammer.com/ruby/downloads/files/
EXTRACT_SUFX=	.tgz

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://www.pragmaticprogrammer.com/ruby/downloads/ri.html
COMMENT=	ri -- Ruby Interactive reference

WRKSRC=		${WRKDIR}/ri
RUBY_REQD=	1.6.2
DIST_SUBDIR=	ruby
USE_RUBY=	yes
NO_BUILD=	# empty

do-install:
	cd ${WRKSRC}; ${RUBY} install.rb

.include "../../lang/ruby-base/Makefile.common"
.include "../../mk/bsd.pkg.mk"
