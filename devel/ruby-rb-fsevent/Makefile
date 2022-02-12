# $NetBSD: Makefile,v 1.8 2022/02/12 12:41:01 taca Exp $

DISTNAME=	rb-fsevent-0.11.1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/thibaudgg/rb-fsevent
COMMENT=	Ruby interface to the Mac OS X FSEvents API
LICENSE=	mit

post-install:
	${RM} ${DESTDIR}${PREFIX}/${GEM_LIBDIR}/.gitignore

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
