# $NetBSD: Makefile,v 1.31 2008/04/25 20:39:09 joerg Exp $

DISTNAME=	roundup-1.1.2
CATEGORIES=	devel
MASTER_SITES=	http://cheeseshop.python.org/packages/source/r/roundup/

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://roundup.sourceforge.net/
COMMENT=	Issue tracking system with command-line, web and email clients

PYDISTUTILSPKG=	yes
PY_PATCHPLIST=	yes
USE_LANGUAGES=

PYTHON_PATCH_SCRIPTS+=	cgi-bin/roundup.cgi demo.py roundup/admin.py
PYTHON_PATCH_SCRIPTS+=	roundup/backends/locking.py
PYTHON_PATCH_SCRIPTS+=	roundup/cgi/TAL/talgettext.py
PYTHON_PATCH_SCRIPTS+=	roundup/msgfmt.py
PYTHON_PATCH_SCRIPTS+=	roundup/scripts/roundup_demo.py
PYTHON_PATCH_SCRIPTS+=	roundup/scripts/roundup_gettext.py
PYTHON_PATCH_SCRIPTS+=	roundup/version_check.py run_tests.py
PYTHON_PATCH_SCRIPTS+=	scripts/add-issue scripts/copy-user.py
PYTHON_PATCH_SCRIPTS+=	scripts/imapServer.py scripts/roundup-reminder
PYTHON_PATCH_SCRIPTS+=	scripts/schema_diagram.py tools/load_tracker.py
PYTHON_PATCH_SCRIPTS+=	tools/migrate-queries.py tools/pygettext.py

ROUNDUPDOCDIR=	${PREFIX}/share/doc/roundup

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/roundup-admin.1 ${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/doc/roundup-demo.1 ${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/doc/roundup-mailgw.1 ${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/doc/roundup-server.1 ${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA_DIR} ${ROUNDUPDOCDIR}
	${INSTALL_DATA} ${WRKSRC}/CHANGES.txt ${ROUNDUPDOCDIR}
	${INSTALL_DATA} ${WRKSRC}/COPYING.txt ${ROUNDUPDOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README.txt ${ROUNDUPDOCDIR}
	cd ${WRKSRC}/doc && ${PAX} -s '/.*\.1//g' -rw -pp -pm . ${ROUNDUPDOCDIR}

.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
