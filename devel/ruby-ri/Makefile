# $NetBSD: Makefile,v 1.2 2003/03/29 12:40:39 jmmv Exp $
#

DISTNAME=	ri-0.7a
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
