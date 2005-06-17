# $NetBSD: Makefile,v 1.15 2005/06/17 03:50:35 jlam Exp $
#

DISTNAME=	rox-lib-1.9.17
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=rox/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	http://rox.sourceforge.net/
COMMENT=	Shared code for ROX applications

DEPENDS+=	rox>=2.2.0:../../sysutils/rox

WRKSRC=		${WRKDIR}/${DISTNAME}/ROX-Lib2
DIST_SUBDIR=	rox

NO_CONFIGURE=	yes
NO_BUILD=	yes

PYTHON_PATCH_SCRIPTS=	AppRun MakeDist
INSTALLATION_DIRS=	share/rox

post-patch:
	${SED} -e s:"/usr/local/lib":"${PREFIX}/share/rox":g	\
		< ${WRKSRC}/Help/findrox.py			\
		> ${WRKSRC}/Help/findrox.py.1
	${MV} -f ${WRKSRC}/Help/findrox.py.1 ${WRKSRC}/Help/findrox.py

pre-install:
	${RM} -f ${WRKSRC}/AppRun.tmp
	${RM} -f ${WRKSRC}/MakeDist.tmp

do-install:
	${CP} -Rf ${WRKSRC} ${PREFIX}/share/rox

.include "../../lang/python/application.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
