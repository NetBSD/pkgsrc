# $NetBSD: Makefile,v 1.2 2002/09/21 23:46:57 jlam Exp $
#

DISTNAME=	Edit-0.1.2
PKGNAME=	rox-edit-0.1.2
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

WRKSRC=		${WRKDIR}/Edit

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
.include "../../x11/pygtk/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
