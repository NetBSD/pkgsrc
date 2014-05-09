# $NetBSD: Makefile,v 1.21 2014/05/09 07:37:01 wiz Exp $

DISTNAME=	ExpectPy-1.9b1
PKGNAME=	${PYPKGPREFIX}-expect-1.9b1
PKGREVISION=	5
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=expectpy/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/expectpy/
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
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # not yet ported as of 1.9b1

EXAMPLESDIR=	${PREFIX}/share/examples/${PYPKGPREFIX}-expect
EXAMPLESFILES=	ask.py glob.py ping.py telnet.py xping.py

INSTALLATION_DIRS=	lib/python${PYVERSSUFFIX}/lib-dynload

post-install:
		${INSTALL_DATA_DIR} ${DESTDIR:Q}${EXAMPLESDIR}
.for f in ${EXAMPLESFILES}
		${INSTALL_DATA} ${WRKSRC}/examples/${f} \
			${DESTDIR:Q}${EXAMPLESDIR}
.endfor

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "DragonFly"
PTHREAD_AUTO_VARS=	yes

.include "../../mk/pthread.buildlink3.mk"
.endif

.include "../../lang/tcl/buildlink3.mk"
.include "../../lang/tcl-expect/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
