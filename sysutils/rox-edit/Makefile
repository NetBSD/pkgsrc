# $NetBSD: Makefile,v 1.17 2006/01/24 07:32:35 wiz Exp $
#

DISTNAME=	Edit-0.1.2
PKGNAME=	rox-edit-0.1.2
PKGREVISION=	6
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=rox/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	http://rox.sourceforge.net/
COMMENT=	Simple text editor for ROX

DEPENDS+=	rox-lib>=0.1.4:../../sysutils/rox-lib

WRKSRC=		${WRKDIR}/Edit
DIST_SUBDIR=	rox

NO_CONFIGURE=	yes
NO_BUILD=	yes

PYTHON_PATCH_SCRIPTS=	AppRun
INSTALLATION_DIRS=	share/rox

post-patch:
	${SED} -e s:"/usr/local/lib":"${PREFIX}/share/rox":g	\
		< ${WRKSRC}/findrox.py			\
		> ${WRKSRC}/findrox.py.1
	${MV} -f ${WRKSRC}/findrox.py.1 ${WRKSRC}/findrox.py

pre-install:
	${RM} -f ${WRKSRC}/AppRun.tmp

do-install:
	${CP} -Rf ${WRKSRC} ${PREFIX}/share/rox

.include "../../lang/python/application.mk"
.include "../../x11/pygtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
