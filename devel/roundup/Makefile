# $NetBSD: Makefile,v 1.9 2003/09/29 12:52:16 recht Exp $

DISTNAME=	roundup-0.6.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=roundup/}

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://roundup.sf.net/
COMMENT=	Issue tracking system with command-line, web and email clients

PYDISTUTILSPKG=	yes
PY_PATCHPLIST=	yes
USE_BUILDLINK2=	yes

PYTHON_VERSIONS_ACCEPTED=	23 23pth 22 22pth 21 21pth

PYTHON_PATCH_SCRIPTS=	roundup/admin.py roundup/backends/locking.py \
			roundup/version_check.py cgi-bin/roundup.cgi

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
