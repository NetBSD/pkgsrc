# $NetBSD: Makefile,v 1.1.1.1 2002/04/13 20:58:53 jwise Exp $
#
# We use the binary distribution of crimson because otherwise we
# have a bootstrap-loop between jakarta-ant and crimson, each of which
# uses the other.

DISTNAME=	${PKGNAME}-bin
PKGNAME=	crimson-1.1.3
CATEGORIES=	textproc www
MASTER_SITES=	http://xml.apache.org/dist/crimson/

MAINTAINER=	jwise@netbsd.org
HOMEPAGE=	http://xml.apache.org/crimson/
COMMENT=	Apache.org implementation of JAXP, SAX, and DOM

WRKSRC=		${WRKDIR}/${PKGNAME}
USE_JAVA=
NO_PATCH=
NO_CONFIGURE=
NO_BUILD=

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/java
	${INSTALL_DATA} ${WRKSRC}/crimson.jar ${PREFIX}/lib/java
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/java/crimson
	cd ${WRKSRC}/docs && ${PAX} -rwpp * ${PREFIX}/share/doc/java/crimson
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/java/crimson
	cd ${WRKSRC}/examples && ${PAX} -rwpp * ${PREFIX}/share/examples/java/crimson

.include "../../mk/bsd.pkg.mk"
