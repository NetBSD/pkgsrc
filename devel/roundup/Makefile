# $NetBSD: Makefile,v 1.41 2012/02/03 13:08:57 obache Exp $

DISTNAME=	roundup-1.4.19
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://pypi.python.org/packages/source/r/roundup/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://roundup.sourceforge.net/
COMMENT=	Issue tracking system with command-line, web and email clients
LICENSE=	mit AND zpl

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=
USE_TOOLS+=	pax

PYTHON_PATCH_SCRIPTS+=	cgi-bin/roundup.cgi demo.py roundup/admin.py
PYTHON_PATCH_SCRIPTS+=	frontends/roundup.cgi
PYTHON_PATCH_SCRIPTS+=	roundup/backends/locking.py
PYTHON_PATCH_SCRIPTS+=	roundup/cgi/TAL/talgettext.py
PYTHON_PATCH_SCRIPTS+=	roundup/msgfmt.py
PYTHON_PATCH_SCRIPTS+=	roundup/scripts/roundup_demo.py
PYTHON_PATCH_SCRIPTS+=	roundup/scripts/roundup_gettext.py
PYTHON_PATCH_SCRIPTS+=	roundup/scripts/roundup_xmlrpc_server.py
PYTHON_PATCH_SCRIPTS+=	roundup/version_check.py run_tests.py
PYTHON_PATCH_SCRIPTS+=	scripts/add-issue scripts/copy-user.py
PYTHON_PATCH_SCRIPTS+=	scripts/imapServer.py scripts/roundup-reminder
PYTHON_PATCH_SCRIPTS+=	scripts/schema_diagram.py tools/load_tracker.py
PYTHON_PATCH_SCRIPTS+=	tools/migrate-queries.py tools/pygettext.py

ROUNDUPDOCDIR=	${PREFIX}/share/doc/roundup

INSTALLATION_DIRS+=	${ROUNDUPDOCDIR} ${PKGMANDIR}/man1

post-install:
	${INSTALL_MAN} ${WRKSRC}/share/man/man1/roundup-admin.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/share/man/man1/roundup-demo.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/share/man/man1/roundup-mailgw.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/share/man/man1/roundup-server.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/CHANGES.txt ${DESTDIR}${ROUNDUPDOCDIR}
	${INSTALL_DATA} ${WRKSRC}/COPYING.txt ${DESTDIR}${ROUNDUPDOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README.txt ${DESTDIR}${ROUNDUPDOCDIR}
	cd ${WRKSRC}/doc && pax -s '/.*\.1//g' -rw -pp -pm . ${DESTDIR}${ROUNDUPDOCDIR}

.include "../../lang/python/distutils.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
