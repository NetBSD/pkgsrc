# $NetBSD: Makefile,v 1.19 2005/09/28 20:52:27 rillig Exp $
#
# We use the binary distribution of crimson because otherwise we
# have a bootstrap-loop between apache-ant and crimson, each of which
# uses the other.

DISTNAME=	${PKGNAME}-bin
PKGNAME=	crimson-1.1.3
CATEGORIES=	textproc www
MASTER_SITES=	http://xml.apache.org/dist/crimson/

MAINTAINER=	jwise@NetBSD.org
HOMEPAGE=	http://xml.apache.org/crimson/
COMMENT=	Apache.org implementation of JAXP, SAX, and DOM

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
USE_JAVA=	run
USE_JAVA2=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/java
	${INSTALL_DATA} ${WRKSRC}/crimson.jar ${PREFIX}/lib/java
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/java/crimson
	cd ${WRKSRC}/docs && ${PAX} -rw -pp * ${PREFIX}/share/doc/java/crimson
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/java/crimson
	cd ${WRKSRC}/examples && ${PAX} -rw -pp * ${PREFIX}/share/examples/java/crimson

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
