# $NetBSD: Makefile,v 1.1.1.1.2.1 2002/06/23 19:00:36 jlam Exp $
#

DISTNAME=	rox-base-1.0.2
PKGREVISION=	1
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
	${INSTALL_DATA_DIR} 	${PREFIX}/share/rox
	${INSTALL_PROGRAM_DIR} 	${PREFIX}/libexec/rox
	${CP} -Rf ${WRKSRC}/Choices ${PREFIX}/share/rox

.include "../../mk/bsd.pkg.mk"
