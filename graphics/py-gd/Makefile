# $NetBSD: Makefile,v 1.7 2001/09/09 20:36:30 agc Exp $

DISTNAME=	gdmodule.c
PKGNAME=	py-gd-1.3
CATEGORIES=	graphics
MASTER_SITES=	http://starship.python.net/~richard/gdmodule/
DISTFILES=	gdmodule.c

MAINTAINER=	tsarna@netbsd.org
HOMEPAGE=	http://starship.python.net/~richard/gdmodule/
COMMENT=	Python interface to gd graphics library

DEPENDS+=	python>=2.0:../../lang/python
DEPENDS+=	gd>=1.8.3:../../graphics/gd

WRKSRC=		${WRKDIR}
EXTRACT_CMD=	${CP} ${DISTDIR}/${DISTNAME} ${WRKSRC}

ALL_TARGET=	default

post-extract:
	${SED}	-e 's,@LOCALBASE@,${LOCALBASE},g' \
		-e 's,@X11BASE@,${X11BASE},g' \
		${FILESDIR}/Setup.in > ${WRKSRC}/Setup.in

do-configure:
	${CP} ${PREFIX}/lib/python2.0/config/Makefile.pre.in ${WRKSRC}
	cd ${WRKSRC}; ${MAKE} -f Makefile.pre.in boot

.include "../../mk/bsd.pkg.mk"
