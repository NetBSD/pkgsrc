# $NetBSD: Makefile,v 1.30 2009/08/20 15:25:00 jwise Exp $
#
# Note: we currently use the pre-built (-bin) distribution of FOP,
# because although FOP runs fine under JDK 1.1, JDK 1.2 or greater is
# required to build it.
#
# Note: please do NOT update this package to a more recent version of FOP --
# this is the most recent version which works with cocoon.
#

DISTNAME=	fop-0_15_0-forBeginners
PKGNAME=	fop-0.15.0
PKGREVISION=	2
CATEGORIES=	textproc www
MASTER_SITES=	http://xmlgraphics.apache.org/dist/fop/recent/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xmlgraphics.apache.org/fop/
COMMENT=	The Apache Project's XSL Formatting Objects implementation

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}
USE_JAVA=	run
USE_TOOLS+=	pax
NO_CONFIGURE=	yes
NO_BUILD=	yes
INSTALLATION_DIRS=	lib/java share/doc/java/fop

.include "../../mk/bsd.prefs.mk"

post-extract:
.if ${OPSYS:M*BSD}
	find -d ${WRKSRC}/docs -name cvs -exec ${RM} -r '{}' \;
.else
	find ${WRKSRC}/docs -depth -name cvs -exec ${RM} -r '{}' \;
.endif
	cd ${WRKSRC} && chmod -R go-w .

do-install:
	${INSTALL_DATA} ${WRKSRC}/build/fop.jar ${DESTDIR}${PREFIX}/lib/java/fop.jar
	${INSTALL_DATA} ${WRKSRC}/lib/w3c.jar ${DESTDIR}${PREFIX}/lib/java/fop-w3c.jar
	cd ${WRKSRC}/docs && pax -rw . ${DESTDIR}${PREFIX}/share/doc/java/fop

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
