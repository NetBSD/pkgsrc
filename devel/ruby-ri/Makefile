# $NetBSD: Makefile,v 1.5 2004/01/20 12:13:29 agc Exp $
#

DISTNAME=	ri-0.8a
PKGNAME=	${RUBY_PKGNAMEPREFIX}${DISTNAME}
CATEGORIES=	devel
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
