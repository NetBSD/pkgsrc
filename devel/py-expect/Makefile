# $NetBSD: Makefile,v 1.2 2002/01/19 15:03:35 drochner Exp $
#

DISTNAME=	ExpectPy-1.9b1
PKGNAME=	${PYPKGPREFIX}-expect-1.9b1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pub/sourceforge/expectpy/}

MAINTAINER=	jwise@netbsd.org
HOMEPAGE=	http://www.sourceforge.net/projects/expectpy/
COMMENT=	Expect module for Python

DEPENDS+=	tcl-expect>=5.32.1:../../lang/tcl-expect

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-python=${LOCALBASE} \
			--with-expect=${LOCALBASE} \
			--with-tcl --enable-shared
CONFIGURE_ENV+=	PYTHON=${PYTHONBIN}
INSTALL_TARGET=	installshared
PY_PATCHPLIST=	yes
PLIST_SUBST+=	PYLIB=${PYLIB} PYPKGPREFIX=${PYPKGPREFIX}

EXAMPLESDIR=	${PREFIX}/share/examples/${PYPKGPREFIX}-expect
EXAMPLESFILES=	ask.py glob.py ping.py telnet.py xping.py

post-install:
		${INSTALL_DATA_DIR} ${EXAMPLESDIR}
.for f in ${EXAMPLESFILES}
		${INSTALL_DATA} ${WRKSRC}/examples/$f ${EXAMPLESDIR}
.endfor

.include "../../lang/python/extension.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
