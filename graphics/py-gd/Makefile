# $NetBSD: Makefile,v 1.15 2004/01/20 12:18:17 agc Exp $

DISTNAME=	gdmodule.c
PKGNAME=	${PYPKGPREFIX}-gd-1.3
PKGREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://starship.python.net/~richard/gdmodule/
DISTFILES=	gdmodule.c

MAINTAINER=	tsarna@NetBSD.org
HOMEPAGE=	http://starship.python.net/~richard/gdmodule/
COMMENT=	Python interface to gd graphics library

EXTRACT_CMD=	${CP} ${DISTDIR}/${DISTNAME} ${WRKSRC}

WRKSRC=		${WRKDIR}
ALL_TARGET=	default
USE_BUILDLINK2=	yes

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

.include "../../graphics/freetype-lib/buildlink2.mk"
.include "../../graphics/gd/buildlink2.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
