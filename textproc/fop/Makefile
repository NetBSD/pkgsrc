# $NetBSD: Makefile,v 1.4 2000/10/19 23:14:50 jwise Exp $
#
# Note: we currently use the pre-built (-bin) distribution of FOP,
# because although FOP runs fine under JDK 1.1, JDK 1.2 or greater is
# required to build it.

DISTNAME=	fop-0_13_0
PKGNAME=	fop-0.13.0
CATEGORIES=	textproc www
MASTER_SITES=	http://xml.apache.org/dist/fop/

MAINTAINER=	jwise@netbsd.org
HOMEPAGE=	http://xml.apache.org/fop/

USE_JAVA=	yes
NO_PATCH=
NO_CONFIGURE=
NO_BUILD=

WRKSRC=		${WRKDIR}/fop-0_13_0

post-extract:
	@${FIND} -d ${WRKSRC} -type d -name CVS -exec ${RM} -rf '{}' \;

do-install:
	${MKDIR} ${PREFIX}/lib/java
	${INSTALL_DATA} ${WRKSRC}/fop_bin_0_13_0.jar ${PREFIX}/lib/java/fop.jar
	${MKDIR} ${PREFIX}/share/doc/java/fop
	cd ${WRKSRC}/docs ; ${GTAR} pcf - . | ( cd ${PREFIX}/share/doc/java/fop ; ${GTAR} pvxf - )
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/doc/java/fop

.include "../../mk/bsd.pkg.mk"
