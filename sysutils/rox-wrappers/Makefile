# $NetBSD: Makefile,v 1.6 2003/07/21 17:24:32 martti Exp $
#

DISTNAME=	Wrappers-1.0.2
PKGNAME=	rox-wrappers-1.0.2
PKGREVISION=	2
WRKSRC=		${WRKDIR}/Wrappers
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=rox/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	http://rox.sourceforge.net/
COMMENT=	Some example Wrapper applications

DEPENDS+=	rox>=1.2.0nb5:../../sysutils/rox

DIST_SUBDIR=	rox

NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:
	${RM} -f ${WRKSRC}/Emacs/AppRun.orig
	${CP} -Rf ${WRKSRC} ${PREFIX}/share/rox

.include "../../mk/bsd.pkg.mk"
