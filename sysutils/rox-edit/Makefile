# $NetBSD: Makefile,v 1.6 2003/05/05 19:05:19 jmmv Exp $
#

DISTNAME=	Edit-0.1.2
PKGNAME=	rox-edit-0.1.2
PKGREVISION=	1
WRKSRC=		${WRKDIR}/Edit
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=rox/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	rxg@netbsd.org
HOMEPAGE=	http://rox.sourceforge.net/
COMMENT=	simple text editor for ROX

DEPENDS+=	rox-lib>=0.1.4:../../sysutils/rox-lib

DIST_SUBDIR=	rox

NO_CONFIGURE=	yes
NO_BUILD=	yes
USE_BUILDLINK2=	yes

PYTHON_PATCH_SCRIPTS=	AppRun

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
.include "../../x11/pygtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
