# $NetBSD: Makefile,v 1.1.1.1 2000/05/31 14:38:10 jwise Exp $
#
# Note: we currently use the pre-built (-bin) distribution of FOP,
# because although FOP runs fine under JDK 1.1, JDK 1.2 or greater is
# required to build it.

DISTNAME=	fop-0_12_1
PKGNAME=	fop-0.12.1
CATEGORIES=	textproc www
MASTER_SITES=	http://xml.apache.org/dist/fop/

MAINTAINER=	jwise@netbsd.org
HOMEPAGE=	http://xml.apache.org/fop/

DEPENDS+=	xalan-j-*:../../textproc/xalan-j

USE_JAVA=	yes
NO_PATCH=
NO_CONFIGURE=
NO_BUILD=

WRKSRC=		${WRKDIR}/fop-0_12_1

do-install:
	${INSTALL_DATA} ${WRKSRC}/fop_bin_0_12_1.jar ${PREFIX}/lib/java/fop.jar
	${MKDIR} ${PREFIX}/share/doc/java/fop
	cd ${WRKSRC}/docs ; ${GTAR} pcf - . | ( cd ${PREFIX}/share/doc/java/fop ; ${GTAR} pvxf - )

.include "../../mk/bsd.pkg.mk"
