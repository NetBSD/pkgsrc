# $NetBSD: Makefile,v 1.2.2.2 2002/06/23 19:00:58 jlam Exp $
#

DISTNAME=	Wrappers-1.0.2
PKGNAME=	rox-wrappers-1.0.2
PKGREVISION=	1
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

WRKSRC=		${WRKDIR}/Wrappers

do-install:
	${RM} -f ${WRKSRC}/Emacs/AppRun.orig
	${CP} -Rf ${WRKSRC} ${PREFIX}/share/rox

.include "../../mk/bsd.pkg.mk"
