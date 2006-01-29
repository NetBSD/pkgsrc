# $NetBSD: Makefile,v 1.1.1.1 2006/01/29 17:39:33 rxg Exp $
#

DISTNAME=	edit-2.0
PKGNAME=	rox-${DISTNAME}
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=rox/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	http://rox.sourceforge.net/desktop/node/20
COMMENT=	Simple text editor for ROX

DEPENDS+=	rox-lib>=2.0.2nb2:../../devel/rox-lib

WRKSRC=		${WRKDIR}/${DISTNAME}/Edit
DIST_SUBDIR=	rox

NO_BUILD=	yes

PYTHON_PATCH_SCRIPTS=	AppRun tests/testreplace.py

INSTALLATION_DIRS=	share/rox/Edit

SUBST_CLASSES+=		lib
SUBST_MESSAGE.lib=	Fixing hardcoded paths for ROX-Lib.
SUBST_STAGE.lib=	post-patch
SUBST_FILES.lib=	findrox.py
SUBST_SED.lib=		-e 's,/usr/local/lib,${PREFIX}/share/rox,g'

post-patch:
	@${FIND} ${WRKSRC} -name 'CVS' -print | ${XARGS} ${RM} -rf
	@${RM} -f ${WRKSRC}/.cvsignore

do-install:
	cd ${WRKSRC} && ${PAX} -rw . ${PREFIX}/share/rox/Edit

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
