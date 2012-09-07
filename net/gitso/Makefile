# $NetBSD: Makefile,v 1.4 2012/09/07 19:17:19 adam Exp $

DISTNAME=		gitso-0.6
PKGREVISION=		1
CATEGORIES=		net x11
MASTER_SITES=		http://gitso.googlecode.com/files/
DISTFILES=		gitso_0.6_linux_all.tar.gz

MAINTAINER=		darcy@NetBSD.org
HOMEPAGE=		http://code.google.com/p/gitso/
COMMENT=		Gitso is to support others
LICENSE=		gnu-gpl-v3

DEPENDS+=		vncviewer-[0-9]*:../../net/vncviewer
DEPENDS+=		x11vnc-[0-9]*:../../x11/x11vnc

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/Gitso

PY_PATCHPLIST=		yes
USE_TOOLS+=		bash:run

REPLACE_BASH+=		run-gitso.sh.local
REPLACE_PYTHON+=	bin/gitso
REPLACE_PYTHON+=	share/gitso/ArgsParser.py
REPLACE_PYTHON+=	share/gitso/ConnectionWindow.py
REPLACE_PYTHON+=	share/gitso/Gitso.py
REPLACE_PYTHON+=	share/gitso/GitsoThread.py
REPLACE_PYTHON+=	share/gitso/NATPMP.py
REPLACE_PYTHON+=	share/gitso/Processes.py

.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"

MAKE_JOBS_SAFE=		no
NO_BUILD=		yes
INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	share/gitso
INSTALLATION_DIRS+=	${PYSITELIB}/gitso

.include "../../mk/bsd.prefs.mk"

SITEFILES=	${WRKSRC}/share/gitso/*.py \
		${WRKSRC}/share/gitso/icon.* \
		${WRKSRC}/share/gitso/icon.* \
		${WRKSRC}/share/gitso/hosts.txt \
		${WRKSRC}/share/doc/gitso/COPYING

post-patch:
	${SED} -e 's|bin/gitso|${DESTDIR}${PREFIX}/bin/gitso|' \
		< ${WRKSRC}/run-gitso.sh \
		> ${WRKSRC}/run-gitso.sh.local

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/run-gitso.sh.local \
		${DESTDIR}${PREFIX}/bin/run-gitso.sh
	${INSTALL_SCRIPT} ${WRKSRC}/bin/gitso ${DESTDIR}${PREFIX}/bin
	for i in ${SITEFILES}; do \
		${INSTALL_DATA} $$i ${DESTDIR}${PREFIX}/${PYSITELIB}/gitso; \
	done

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/py-wxWidgets/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
