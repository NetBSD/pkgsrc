# $NetBSD: Makefile,v 1.25 2012/10/25 06:55:45 asau Exp $
#
# We use the binary distribution of crimson because otherwise we
# have a bootstrap-loop between apache-ant and crimson, each of which
# uses the other.

DISTNAME=	crimson-1.1.3-bin
PKGNAME=	${DISTNAME:S/-bin//}
PKGREVISION=	1
CATEGORIES=	textproc www
MASTER_SITES=	http://xml.apache.org/dist/crimson/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xml.apache.org/crimson/
COMMENT=	Apache.org implementation of JAXP, SAX, and DOM

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
USE_JAVA=	run
USE_JAVA2=	yes
USE_TOOLS+=	pax
NO_CONFIGURE=	yes
NO_BUILD=	yes

INSTALLATION_DIRS=	lib/java share/doc/java/crimson share/examples/java/crimson

do-install:
	${INSTALL_DATA} ${WRKSRC}/crimson.jar ${DESTDIR}${PREFIX}/lib/java
	cd ${WRKSRC}/docs && pax -rw -pp * ${DESTDIR}${PREFIX}/share/doc/java/crimson
	cd ${WRKSRC}/examples && pax -rw -pp * ${DESTDIR}${PREFIX}/share/examples/java/crimson

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
