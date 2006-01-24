# $NetBSD: Makefile,v 1.10 2006/01/24 07:32:36 wiz Exp $
#

DISTNAME=	Wrappers-1.0.2
PKGNAME=	rox-wrappers-1.0.2
PKGREVISION=	4
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=rox/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	http://rox.sourceforge.net/
COMMENT=	Some example Wrapper applications

DEPENDS+=	rox>=1.2.0nb5:../../sysutils/rox

WRKSRC=		${WRKDIR}/Wrappers
DIST_SUBDIR=	rox

NO_CONFIGURE=	yes
NO_BUILD=	yes

INSTALLATION_DIRS=	share/rox

do-install:
	${RM} -f ${WRKSRC}/Emacs/AppRun.orig
	${CP} -Rf ${WRKSRC} ${PREFIX}/share/rox

.include "../../mk/bsd.pkg.mk"
