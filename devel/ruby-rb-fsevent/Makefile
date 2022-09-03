# $NetBSD: Makefile,v 1.9 2022/09/03 14:40:27 taca Exp $

DISTNAME=	rb-fsevent-0.11.2
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/thibaudgg/rb-fsevent
COMMENT=	Ruby interface to the Mac OS X FSEvents API
LICENSE=	mit

post-install:
	${RM} ${DESTDIR}${PREFIX}/${GEM_LIBDIR}/.gitignore

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
