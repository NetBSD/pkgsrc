# $NetBSD: Makefile,v 1.10 2001/11/14 14:47:55 agc Exp $
#
# Note: we currently use the pre-built (-bin) distribution of FOP,
# because although FOP runs fine under JDK 1.1, JDK 1.2 or greater is
# required to build it.
#
# Note: please do NOT update this package to a more recent version of FOP --
# this is the most recent version which works with cocoon.  If you need a
# newer version, let me know, and I will import the latest version as
# fop-current -- jwise@netbsd.org
#

DISTNAME=	fop-0_15_0-forBeginners
PKGNAME=	fop-0.15.0
WRKSRC=		${WRKDIR}
CATEGORIES=	textproc www
MASTER_SITES=	http://xml.apache.org/dist/fop/recent/
EXTRACT_SUFX=	.zip

MAINTAINER=	jwise@netbsd.org
HOMEPAGE=	http://xml.apache.org/fop/
COMMENT=	the Apache Project's XSL Formatting Objects implementation

USE_JAVA=	yes
NO_PATCH=
NO_CONFIGURE=
NO_BUILD=

post-extract:
	${FIND} -d ${WRKSRC}/docs -name cvs -exec ${RM} -r '{}' \;

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/java
	${INSTALL_DATA} ${WRKSRC}/build/fop.jar ${PREFIX}/lib/java/fop.jar
	${INSTALL_DATA} ${WRKSRC}/lib/w3c.jar ${PREFIX}/lib/java/fop-w3c.jar
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/java/fop
	cd ${WRKSRC}/docs && ${PAX} -rwpe . ${PREFIX}/share/doc/java/fop
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/doc/java/fop

.include "../../mk/bsd.pkg.mk"
