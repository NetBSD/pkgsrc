# $NetBSD: Makefile,v 1.22 2004/06/28 17:28:57 abs Exp $
#
# Note: we currently use the pre-built (-bin) distribution of FOP,
# because although FOP runs fine under JDK 1.1, JDK 1.2 or greater is
# required to build it.
#
# Note: please do NOT update this package to a more recent version of FOP --
# this is the most recent version which works with cocoon.  If you need a
# newer version, let me know, and I will import the latest version as
# fop-current -- jwise@NetBSD.org
#

DISTNAME=	fop-0_15_0-forBeginners
PKGNAME=	fop-0.15.0
CATEGORIES=	textproc www
MASTER_SITES=	http://xml.apache.org/dist/fop/recent/
EXTRACT_SUFX=	.zip

MAINTAINER=	jwise@NetBSD.org
HOMEPAGE=	http://xml.apache.org/fop/
COMMENT=	The Apache Project's XSL Formatting Objects implementation

WRKSRC=		${WRKDIR}
USE_JAVA=	run
USE_BUILDLINK3= YES
NO_CONFIGURE=
NO_BUILD=

.include "../../mk/bsd.prefs.mk"

post-extract:
.if ${OPSYS:M*BSD}
	${FIND} -d ${WRKSRC}/docs -name cvs -exec ${RM} -r '{}' \;
.else
	${FIND} ${WRKSRC}/docs -depth -name cvs -exec ${RM} -r '{}' \;
.endif

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/java
	${INSTALL_DATA} ${WRKSRC}/build/fop.jar ${PREFIX}/lib/java/fop.jar
	${INSTALL_DATA} ${WRKSRC}/lib/w3c.jar ${PREFIX}/lib/java/fop-w3c.jar
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/java/fop
	cd ${WRKSRC}/docs && ${PAX} -rw -pp . ${PREFIX}/share/doc/java/fop

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
