# $NetBSD: Makefile,v 1.12 2004/10/03 00:18:16 tv Exp $
#

DISTNAME=	ROX-Lib-0.1.4
PKGNAME=	rox-lib-0.1.4
PKGREVISION=	4
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=rox/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	http://rox.sourceforge.net/
COMMENT=	Shared code for ROX applications

DEPENDS+=	rox>=1.2.0nb2:../../sysutils/rox

WRKSRC=		${WRKDIR}/ROX-Lib
DIST_SUBDIR=	rox

NO_CONFIGURE=	yes
NO_BUILD=	yes
USE_BUILDLINK3=	yes

PYTHON_PATCH_SCRIPTS=	AppRun bin/savebox

post-patch:
	${SED} -e s:"/usr/local/lib":"${PREFIX}/share/rox":g	\
		< ${WRKSRC}/Help/findrox.py			\
		> ${WRKSRC}/Help/findrox.py.1
	${MV} -f ${WRKSRC}/Help/findrox.py.1 ${WRKSRC}/Help/findrox.py

pre-install:
	${RM} -f ${WRKSRC}/AppRun.tmp
	${RM} -f ${WRKSRC}/bin/savebox.tmp

do-install:
	${CP} -Rf ${WRKSRC} ${PREFIX}/share/rox

.include "../../lang/python/application.mk"
.include "../../x11/pygtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
