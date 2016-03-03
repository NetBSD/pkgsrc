# $NetBSD: Makefile,v 1.1 2016/03/03 14:37:46 jmmv Exp $

DISTNAME=	rb-fsevent-0.9.7
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/thibaudgg/rb-fsevent
COMMENT=	Ruby interface to the Mac OS X FSEvents API
LICENSE=	mit

ONLY_FOR_PLATFORM=	Darwin-*-*

post-install:
	${RM} ${DESTDIR}${PREFIX}/${GEM_LIBDIR}/.gitignore

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
