# $NetBSD: Makefile,v 1.1.1.1 2002/06/15 13:23:08 cjep Exp $
#

DISTNAME=	Archive-0.1.2
PKGNAME=	rox-archive-0.1.2
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=rox/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	rxg@netbsd.org
HOMEPAGE=	http://rox.sourceforge.net/
COMMENT=	simple archiver

DEPENDS+=	rox-lib>=0.1.4:../../sysutils/rox-lib

DIST_SUBDIR=	rox

USE_PERL5=	yes

NO_CONFIGURE=	yes
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/Archive

APPDIR=		${PREFIX}/share/rox

post-patch:
	${CP} ${WRKSRC}/AppRun ${WRKSRC}/AppRun.1
	${SED} -e s:@APPDIR@:"${APPDIR}":g < ${WRKSRC}/AppRun.1 	\
				> ${WRKSRC}/AppRun
	${RM} ${WRKSRC}/AppRun.1 ${WRKSRC}/AppRun.orig

do-install:
	${CP} -Rf ${WRKSRC} ${APPDIR}

.include "../../mk/bsd.pkg.mk"
