# $NetBSD: Makefile,v 1.8 2004/01/20 12:26:16 agc Exp $
#

DISTNAME=	Archive-0.1.2
PKGNAME=	rox-archive-0.1.2
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=rox/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	http://rox.sourceforge.net/
COMMENT=	Simple archiver

# no real libraries there
DEPENDS+=	rox-lib>=0.1.4nb1:../../sysutils/rox-lib

WRKSRC=		${WRKDIR}/Archive
DIST_SUBDIR=	rox

USE_BUILDLINK2=	yes
USE_PERL5=	yes

NO_CONFIGURE=	yes
NO_BUILD=	yes

APPDIR=		${PREFIX}/share/rox

post-patch:
	${CP} ${WRKSRC}/AppRun ${WRKSRC}/AppRun.1
	${SED} -e s:@APPDIR@:"${APPDIR}":g < ${WRKSRC}/AppRun.1 	\
				> ${WRKSRC}/AppRun
	${RM} ${WRKSRC}/AppRun.1 ${WRKSRC}/AppRun.orig

do-install:
	${CP} -Rf ${WRKSRC} ${APPDIR}

.include "../../mk/bsd.pkg.mk"
