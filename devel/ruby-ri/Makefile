# $NetBSD: Makefile,v 1.3 2003/04/21 13:34:20 taca Exp $
#

DISTNAME=	ri-0.8a
PKGNAME=	${RUBY_PKGNAMEPREFIX}${DISTNAME}
WRKSRC=		${WRKDIR}/ri
CATEGORIES=	devel
MASTER_SITES=	http://www.pragmaticprogrammer.com/ruby/downloads/files/
EXTRACT_SUFX=	.tgz

MAINTAINER=	taca@netbsd.org
HOMEPAGE=	http://www.pragmaticprogrammer.com/ruby/downloads/ri.html
COMMENT=	ri -- Ruby Interactive reference

RUBY_REQD=	1.6.2
DIST_SUBDIR=	ruby
USE_RUBY=	yes
NO_BUILD=	# empty

do-install:
	cd ${WRKSRC}; ${RUBY} install.rb

.include "../../lang/ruby-base/Makefile.common"
.include "../../mk/bsd.pkg.mk"
