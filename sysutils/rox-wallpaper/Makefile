# $NetBSD: Makefile,v 1.2 2002/09/21 23:46:58 jlam Exp $
#

DISTNAME=	Wallpaper-0.1.1
PKGNAME=	rox-wallpaper-0.1.1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=rox/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	rxg@netbsd.org
HOMEPAGE=	http://rox.sourceforge.net/
COMMENT=	For setting the backdrop

DEPENDS+=	rox-lib>=0.1.4:../../sysutils/rox-lib
DEPENDS+=	ImageMagick>=5.3.9:../../graphics/ImageMagick

DIST_SUBDIR=	rox

NO_CONFIGURE=	yes
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/Wallpaper

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
.include "../../x11/pygtk/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
