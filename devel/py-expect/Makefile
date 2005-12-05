# $NetBSD: Makefile,v 1.10 2005/12/05 20:50:07 rillig Exp $
#

DISTNAME=	ExpectPy-1.9b1
PKGNAME=	${PYPKGPREFIX}-expect-1.9b1
PKGREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pub/sourceforge/expectpy/}

MAINTAINER=	jwise@NetBSD.org
HOMEPAGE=	http://www.sourceforge.net/projects/expectpy/
COMMENT=	Expect module for Python

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-python=${BUILDLINK_PREFIX.${PYPACKAGE}} \
			--with-expect=${BUILDLINK_PREFIX.tcl-expect} \
			--with-tcl --enable-shared
CONFIGURE_ENV+=	PYTHON=${PYTHONBIN:Q}
CONFIGURE_ENV+=	PYTH_CONFIGDIR=${BUILDLINK_PREFIX.${PYPACKAGE}}/${PYLIB}/config
INSTALL_TARGET=	installshared
PY_PATCHPLIST=	yes
PLIST_SUBST+=	PYLIB=${PYLIB:Q} PYPKGPREFIX=${PYPKGPREFIX:Q}

EXAMPLESDIR=	${PREFIX}/share/examples/${PYPKGPREFIX}-expect
EXAMPLESFILES=	ask.py glob.py ping.py telnet.py xping.py

post-install:
		${INSTALL_DATA_DIR} ${EXAMPLESDIR}
.for f in ${EXAMPLESFILES}
		${INSTALL_DATA} ${WRKSRC}/examples/${f} ${EXAMPLESDIR}
.endfor

.include "../../lang/tcl/buildlink3.mk"
.include "../../lang/tcl-expect/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
