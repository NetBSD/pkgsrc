# $NetBSD: Makefile,v 1.12 2004/02/16 20:43:27 recht Exp $

DISTNAME=	roundup-0.6.5
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=roundup/}

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://roundup.sf.net/
COMMENT=	Issue tracking system with command-line, web and email clients

PYDISTUTILSPKG=	yes
PY_PATCHPLIST=	yes
USE_BUILDLINK3=	yes

PYTHON_VERSIONS_ACCEPTED=	23 23pth 22 22pth 21 21pth

PYTHON_PATCH_SCRIPTS=	cgi-bin/roundup.cgi demo.py roundup/admin.py
PYTHON_PATCH_SCRIPTS+=	roundup/backends/locking.py roundup/version_check.py
PYTHON_PATCH_SCRIPTS+=	run_tests scripts/add-issue scripts/roundup-reminder
PYTHON_PATCH_SCRIPTS+=	setup.py tools/migrate-queries.py tools/pygettext.py

ROUNDUPDOCDIR=	${PREFIX}/share/doc/roundup

post-install:
	cd ${WRKSRC}/doc && ${INSTALL_MAN} roundup-admin.1 roundup-server.1 \
		roundup-mailgw.1 ${PREFIX}/man/man1
	${INSTALL_DATA_DIR} ${ROUNDUPDOCDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} CHANGES.txt COPYING.txt README.txt \
		${ROUNDUPDOCDIR}
	cd ${WRKSRC}/doc && ${INSTALL_DATA} *.txt *.html *.css ${ROUNDUPDOCDIR}
	${INSTALL_DATA_DIR} ${ROUNDUPDOCDIR}/images
	cd ${WRKSRC}/doc/images && ${INSTALL_DATA} *.png \
		${ROUNDUPDOCDIR}/images

.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
