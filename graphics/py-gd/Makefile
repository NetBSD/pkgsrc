# $NetBSD: Makefile,v 1.10 2002/09/21 23:46:50 jlam Exp $

DISTNAME=	gdmodule.c
PKGNAME=	${PYPKGPREFIX}-gd-1.3
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://starship.python.net/~richard/gdmodule/
DISTFILES=	gdmodule.c

MAINTAINER=	tsarna@netbsd.org
HOMEPAGE=	http://starship.python.net/~richard/gdmodule/
COMMENT=	Python interface to gd graphics library

DEPENDS+=	gd>=1.8.4nb1:../../graphics/gd

WRKSRC=		${WRKDIR}
EXTRACT_CMD=	${CP} ${DISTDIR}/${DISTNAME} ${WRKSRC}

ALL_TARGET=	default

# this pkg uses Makefile.pre.in
PYTHON_VERSIONS_ACCEPTED=	20 21
BUILDLINK_DEPENDS.python20=	python20>=2.0.1nb1
BUILDLINK_DEPENDS.python21=	python21>=2.1.1nb1

PY_PATCHPLIST=	yes

post-extract:
	${SED}	-e 's,@LOCALBASE@,${LOCALBASE},g' \
		-e 's,@X11BASE@,${X11BASE},g' \
		${FILESDIR}/Setup.in > ${WRKSRC}/Setup.in

do-configure:
	${CP} ${PREFIX}/${PYLIB}/config/Makefile.pre.in ${WRKSRC}
	cd ${WRKSRC}; ${MAKE} -f Makefile.pre.in boot

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
