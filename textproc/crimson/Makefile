# $NetBSD: Makefile,v 1.6.2.1 2003/04/20 11:18:54 grant Exp $
#
# We use the binary distribution of crimson because otherwise we
# have a bootstrap-loop between jakarta-ant and crimson, each of which
# uses the other.

DISTNAME=	${PKGNAME}-bin
PKGNAME=	crimson-1.1.3.1
WRKSRC=		${WRKDIR}/${PKGNAME_NOREV:S/.1$//}
CATEGORIES=	textproc www
MASTER_SITES=	http://xml.apache.org/dist/crimson/

MAINTAINER=	jwise@netbsd.org
HOMEPAGE=	http://xml.apache.org/crimson/
COMMENT=	Apache.org implementation of JAXP, SAX, and DOM

USE_JAVA=	run
USE_BUILDLINK2=	# defined
NO_CONFIGURE=	# defined
NO_BUILD=	# defined

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/java
	${INSTALL_DATA} ${WRKSRC}/crimson.jar ${PREFIX}/lib/java
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/java/crimson
	cd ${WRKSRC}/docs && ${PAX} -rw -pp * ${PREFIX}/share/doc/java/crimson
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/java/crimson
	cd ${WRKSRC}/examples && ${PAX} -rw -pp * ${PREFIX}/share/examples/java/crimson

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
