# $NetBSD: Makefile,v 1.3 2003/03/29 12:42:32 jmmv Exp $
#

DISTNAME=	Wrappers-1.0.2
PKGNAME=	rox-wrappers-1.0.2
PKGREVISION=	1
WRKSRC=		${WRKDIR}/Wrappers
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=rox/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	rxg@netbsd.org
HOMEPAGE=	http://rox.sourceforge.net/
COMMENT=	some example Wrapper applications

DEPENDS+=	rox>=1.2.0nb2:../../sysutils/rox

DIST_SUBDIR=	rox

NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:
	${RM} -f ${WRKSRC}/Emacs/AppRun.orig
	${CP} -Rf ${WRKSRC} ${PREFIX}/share/rox

.include "../../mk/bsd.pkg.mk"
