# $NetBSD: Makefile,v 1.21 2005/01/23 20:41:46 recht Exp $

DISTNAME=	roundup-0.7.9
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=roundup/}

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://roundup.sf.net/
COMMENT=	Issue tracking system with command-line, web and email clients

PYDISTUTILSPKG=	yes
PY_PATCHPLIST=	yes
USE_BUILDLINK3=	yes
USE_LANGUAGES=

PYTHON_VERSIONS_ACCEPTED=	24 23 22 21

PYTHON_PATCH_SCRIPTS=	cgi-bin/roundup.cgi demo.py roundup/admin.py
PYTHON_PATCH_SCRIPTS+=	roundup/backends/locking.py roundup/version_check.py
PYTHON_PATCH_SCRIPTS+=	run_tests.py scripts/add-issue scripts/copy-user.py
PYTHON_PATCH_SCRIPTS+=	scripts/roundup-reminder scripts/schema_diagram.py
PYTHON_PATCH_SCRIPTS+=	tools/load_tracker.py tools/migrate-queries.py
PYTHON_PATCH_SCRIPTS+=	tools/pygettext.py

ROUNDUPDOCDIR=	${PREFIX}/share/doc/roundup

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/roundup-admin.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/roundup-mailgw.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/roundup-server.1 ${PREFIX}/man/man1
	${INSTALL_DATA_DIR} ${ROUNDUPDOCDIR}
	${INSTALL_DATA} ${WRKSRC}/CHANGES.txt ${ROUNDUPDOCDIR}
	${INSTALL_DATA} ${WRKSRC}/COPYING.txt ${ROUNDUPDOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README.txt ${ROUNDUPDOCDIR}
	cd ${WRKSRC}/doc && ${PAX} -s '/.*\.1//g' -rw -pp -pm . ${ROUNDUPDOCDIR}

.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
