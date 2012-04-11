# $NetBSD: Makefile,v 1.1 2012/04/11 17:42:06 darcy Exp $

DISTNAME=		gitso-0.6
CATEGORIES=		net x11
MASTER_SITES=		http://gitso.googlecode.com/files/
DISTFILES=		gitso_0.6_linux_all.tar.gz

MAINTAINER=		darcy@NetBSD.org
HOMEPAGE=		http://code.google.com/p/gitso/
COMMENT=		Gitso is to support others

LICENSE=                gnu-gpl-v3
WRKSRC=                 ${WRKDIR}/Gitso

PY_PATCHPLIST=          yes
USE_TOOLS+=             bash:run

REPLACE_BASH+=          run-gitso.sh
REPLACE_PYTHON+=        bin/gitso
REPLACE_PYTHON+=        share/gitso/ArgsParser.py
REPLACE_PYTHON+=        share/gitso/ConnectionWindow.py
REPLACE_PYTHON+=        share/gitso/Gitso.py
REPLACE_PYTHON+=        share/gitso/GitsoThread.py
REPLACE_PYTHON+=        share/gitso/NATPMP.py
REPLACE_PYTHON+=        share/gitso/Processes.py

.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"

PKG_DESTDIR_SUPPORT=	user-destdir
MAKE_JOBS_SAFE=		no
NO_BUILD=               yes
INSTALLATION_DIRS+=     bin
INSTALLATION_DIRS+=     ${PYSITELIB}/gitso

.include "../../mk/bsd.prefs.mk"

DEPENDS+=		vncviewer-[0-9]*:../../net/vncviewer
DEPENDS+=		x11vnc-[0-9]*:../../x11/x11vnc

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/gitso ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/run-gitso.sh ${DESTDIR}${PREFIX}/bin
	for i in ${WRKSRC}/share/gitso/*; do \
		${INSTALL_DATA} $$i ${DESTDIR}${PREFIX}/${PYSITELIB}/gitso; \
	done

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/py-wxWidgets/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
