# $NetBSD: Makefile,v 1.1.1.1 2001/07/01 14:41:20 taca Exp $
#

DISTNAME=	ri-0.7a
PKGNAME=	${RUBY_PKGNAMEPREFIX}${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	http://www.pragmaticprogrammer.com/ruby/downloads/files/
EXTRACT_SUFX=	.tgz

MAINTAINER=	taca@netbsd.org
HOMEPAGE=	http://www.pragmaticprogrammer.com/ruby/downloads/ri.html
COMMENT=	ri -- Ruby Interactive reference

RUBY_REQD=	1.6.2
DIST_SUBDIR=	ruby
WRKSRC=		${WRKDIR}/ri
USE_RUBY=	yes
NO_BUILD=	# empty

do-install:
	cd ${WRKSRC}; ${RUBY} install.rb

.include "../../lang/ruby-base/Makefile.common"
.include "../../mk/bsd.pkg.mk"
