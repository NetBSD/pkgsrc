# $NetBSD: Makefile,v 1.4 2017/09/06 14:14:31 taca Exp $

DISTNAME=	rb-fsevent-0.10.2
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/thibaudgg/rb-fsevent
COMMENT=	Ruby interface to the Mac OS X FSEvents API
LICENSE=	mit

post-install:
	${RM} ${DESTDIR}${PREFIX}/${GEM_LIBDIR}/.gitignore

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
