# $NetBSD: Makefile,v 1.2 2001/02/16 14:38:59 wiz Exp $
#

DISTNAME=	${PY_DISTNAME}
PKGNAME=	py-idle-0.6
CATEGORIES=	devel
MASTER_SITES=	${PY_MASTER_SITES}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.python.org/idle/
COMMENT=	IDLE - The Integrated DeveLopment Environment for Python

DEPENDS+=	py-Tk>=${PY_VERSION}:../../x11/py-Tk

USE_X11=	yes
WRKSRC=		${WRKDIR}/Python-${PY_VERSION}/Tools

EXTRACT_ELEMENTS=	Python-${PY_VERSION}/Tools/idle/*

do-build:
	${PY_COMPILEDIR} ${WRKSRC}/idle

do-install:
	${INSTALL_SCRIPT_DIR} ${PY_LIBDIR}/idle
	${INSTALL_SCRIPT_DIR} ${PY_LIBDIR}/idle/Icons
	${INSTALL_DATA} ${WRKSRC}/idle/*.py ${PY_LIBDIR}/idle
	${INSTALL_DATA} ${WRKSRC}/idle/*.pyc ${PY_LIBDIR}/idle
	${INSTALL_DATA} ${WRKSRC}/idle/*.txt ${PY_LIBDIR}/idle
	${INSTALL_DATA} ${WRKSRC}/idle/ChangeLog ${PY_LIBDIR}/idle
	${INSTALL_DATA} ${WRKSRC}/idle/Icons/* ${PY_LIBDIR}/idle/Icons
	${INSTALL_SCRIPT} ${WRKSRC}/idle/BrowserControl.py ${PY_LIBDIR}/idle
	${INSTALL_SCRIPT} ${WRKSRC}/idle/idle.py ${PY_LIBDIR}/idle

post-install:
	${LN} -s ${PY_LIBDIR}/idle/idle.py \
		${LOCALBASE}/bin/idle

.include "../../lang/python/Makefile.inc"
.include "../../mk/bsd.pkg.mk"
