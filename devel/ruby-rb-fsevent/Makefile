# $NetBSD: Makefile,v 1.1.8.1 2017/01/13 19:36:50 bsiegert Exp $

DISTNAME=	rb-fsevent-0.9.7
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/thibaudgg/rb-fsevent
COMMENT=	Ruby interface to the Mac OS X FSEvents API
LICENSE=	mit

post-install:
	${RM} ${DESTDIR}${PREFIX}/${GEM_LIBDIR}/.gitignore

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
