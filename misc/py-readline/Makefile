# $NetBSD: Makefile,v 1.13 2000/10/22 20:01:50 tsarna Exp $
#

DISTNAME=	${PY_DISTNAME}
PKGNAME=	py-readline-${PY_VERSION}
WRKSRC=		${PY_WRKSRC}
CATEGORIES=	misc
MASTER_SITES=	${PY_MASTER_SITES}

MAINTAINER=	tsarna@netbsd.org
HOMEPAGE=	http://www.python.org/doc/tut/interacting.html

DEPENDS+=	readline>=4.0:../../devel/readline

EXTRACT_ELEMENTS=	${PY_MODULES}/readline.c

do-configure:	python-std-do-configure

do-install:
	${INSTALL_DATA} ${WRKSRC}/readline.so ${PY_LIBDIR}/lib-dynload

.include "../../lang/python/Makefile.inc"
.include "../../mk/bsd.pkg.mk"
