# $NetBSD: Makefile,v 1.12 2004/10/03 00:18:16 tv Exp $
#

DISTNAME=	Memo-1.0.0
PKGNAME=	rox-memo-1.0.0
PKGREVISION=	4
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=rox/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	http://rox.sourceforge.net/
COMMENT=	Reminds you about things

DEPENDS+=	rox-lib>=0.1.4:../../sysutils/rox-lib

DIST_SUBDIR=	rox
WRKSRC=		${WRKDIR}/Memo

NO_CONFIGURE=	yes
NO_BUILD=	yes
USE_BUILDLINK3=	yes

PYTHON_PATCH_SCRIPTS=	AppRun

post-patch:
	${SED} -e s:"/usr/local/lib":"${PREFIX}/share/rox":g	\
		< ${WRKSRC}/findrox.py				\
		> ${WRKSRC}/findrox.py.1
	${MV} -f ${WRKSRC}/findrox.py.1 ${WRKSRC}/findrox.py

pre-install:
	${RM} -f ${WRKSRC}/AppRun.tmp

do-install:
	${CP} -Rf ${WRKSRC} ${PREFIX}/share/rox

.include "../../lang/python/application.mk"
.include "../../x11/pygtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
