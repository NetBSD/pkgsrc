# $NetBSD: Makefile,v 1.1.1.1 1999/05/02 17:48:37 tsarna Exp $

DISTNAME=	gdmodule.c
PKGNAME=	py-gd-1.3
CATEGORIES=	graphics
MASTER_SITES=	http://starship.python.net/~richard/gdmodule/
DISTFILES=	gdmodule.c

MAINTAINER=	tsarna@netbsd.org
HOMEPAGE=	http://starship.python.net/~richard/gdmodule/

DEPENDS+=	python-1.5.2:../../lang/python \
		gd-1.3:../../graphics/gd

WRKSRC=		${WRKDIR}/build

ALL_TARGET=	default

do-extract:
	${MKDIR} ${WRKSRC}
	${CP} ${DISTDIR}/${DISTNAME} ${WRKSRC}
	${SED} -e 's,@PREFIX@,${PREFIX},g' ${FILESDIR}/Setup.in \
		>${WRKSRC}/Setup.in

do-configure:
	${CP} ${PREFIX}/lib/python1.5/config/Makefile.pre.in ${WRKSRC}
	(cd ${WRKSRC}; ${MAKE} -f Makefile.pre.in boot)

.include "../../mk/bsd.pkg.mk"
