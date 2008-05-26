# $NetBSD: Makefile,v 1.22 2008/05/26 02:13:24 joerg Exp $
#
# We use the binary distribution of crimson because otherwise we
# have a bootstrap-loop between apache-ant and crimson, each of which
# uses the other.

DISTNAME=	crimson-1.1.3-bin
PKGNAME=	${DISTNAME:S/-bin//}
PKGREVISION=	1
CATEGORIES=	textproc www
MASTER_SITES=	http://xml.apache.org/dist/crimson/

MAINTAINER=	jwise@NetBSD.org
HOMEPAGE=	http://xml.apache.org/crimson/
COMMENT=	Apache.org implementation of JAXP, SAX, and DOM

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
USE_JAVA=	run
USE_JAVA2=	yes
USE_TOOLS+=	pax
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/java
	${INSTALL_DATA} ${WRKSRC}/crimson.jar ${PREFIX}/lib/java
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/java/crimson
	cd ${WRKSRC}/docs && pax -rw -pp * ${PREFIX}/share/doc/java/crimson
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/java/crimson
	cd ${WRKSRC}/examples && pax -rw -pp * ${PREFIX}/share/examples/java/crimson

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
