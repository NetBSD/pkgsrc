# $NetBSD: Makefile,v 1.6 2020/05/06 07:37:52 taca Exp $

DISTNAME=	rb-fsevent-0.10.4
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/thibaudgg/rb-fsevent
COMMENT=	Ruby interface to the Mac OS X FSEvents API
LICENSE=	mit

post-install:
	${RM} ${DESTDIR}${PREFIX}/${GEM_LIBDIR}/.gitignore

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
