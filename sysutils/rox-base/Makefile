# $NetBSD: Makefile,v 1.1.1.1 2002/04/21 11:25:07 rh Exp $
#

DISTNAME=	rox-base-1.0.2
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=rox/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	rxg@netbsd.org
HOMEPAGE=	http://rox.sourceforge.net/
COMMENT=	Shared ROX resources

DIST_SUBDIR=	rox

NO_CONFIGURE=	yes
NO_BUILD=	yes

post-extract:
	${FIND} ${WRKSRC} -name CVS | xargs ${RM} -rf

do-install:
	${CP} -Rf ${WRKSRC}/Choices ${PREFIX}/share

.include "../../mk/bsd.pkg.mk"
