# $NetBSD: Makefile,v 1.3 1999/11/01 03:34:31 jlam Exp $

DISTNAME=	gdmodule.c
PKGNAME=	py-gd-1.3
CATEGORIES=	graphics
MASTER_SITES=	http://starship.python.net/~richard/gdmodule/
DISTFILES=	gdmodule.c

MAINTAINER=	tsarna@netbsd.org
HOMEPAGE=	http://starship.python.net/~richard/gdmodule/

DEPENDS+=	python-1.5.2:../../lang/python
DEPENDS+=	gd-1.7.3:../../graphics/gd

NO_WRKSUBDIR=	yes
EXTRACT_CMD=	${CP} ${DISTDIR}/${DISTNAME} ${WRKSRC}

ALL_TARGET=	default

post-extract:
	${SED}	-e 's,@LOCALBASE@,${LOCALBASE},g' \
		-e 's,@X11BASE@,${X11BASE},g' \
		${FILESDIR}/Setup.in > ${WRKSRC}/Setup.in

do-configure:
	${CP} ${PREFIX}/lib/python1.5/config/Makefile.pre.in ${WRKSRC}
	cd ${WRKSRC}; ${MAKE} -f Makefile.pre.in boot

.include "../../mk/bsd.pkg.mk"
