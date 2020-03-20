# $NetBSD: Makefile,v 1.14 2020/03/20 11:57:34 nia Exp $
#

DISTNAME=	edit-2.0
PKGNAME=	rox-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=rox/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	http://rox.sourceforge.net/desktop/node/20
COMMENT=	Simple text editor for ROX

DEPENDS+=	rox-lib>=2.0.2nb2:../../devel/rox-lib

USE_TOOLS+=	pax

WRKSRC=		${WRKDIR}/${DISTNAME}/Edit
DIST_SUBDIR=	rox

NO_BUILD=	yes

REPLACE_PYTHON=	AppRun tests/testreplace.py

INSTALLATION_DIRS=	share/rox/Edit

SUBST_CLASSES+=		lib
SUBST_MESSAGE.lib=	Fixing hardcoded paths for ROX-Lib.
SUBST_STAGE.lib=	pre-configure
SUBST_FILES.lib=	findrox.py
SUBST_SED.lib=		-e 's,/usr/local/lib,${PREFIX}/share/rox,g'

post-patch:
	@${FIND} ${WRKSRC} -name 'CVS' -print | ${XARGS} ${RM} -rf
	@${RM} -f ${WRKSRC}/.cvsignore

do-install:
	cd ${WRKSRC} && pax -rw . ${DESTDIR}${PREFIX}/share/rox/Edit

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
