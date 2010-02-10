# $NetBSD: Makefile,v 1.6 2010/02/10 19:17:37 joerg Exp $
#

DISTNAME=	edit-2.0
PKGNAME=	rox-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=rox/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	http://rox.sourceforge.net/desktop/node/20
COMMENT=	Simple text editor for ROX

DEPENDS+=	rox-lib>=2.0.2nb2:../../devel/rox-lib

USE_TOOLS+=	pax

PKG_DESTDIR_SUPPORT=	user-destdir

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
	cd ${WRKSRC} && pax -rw . ${DESTDIR}${PREFIX}/share/rox/Edit

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
