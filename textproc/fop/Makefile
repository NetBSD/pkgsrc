# $NetBSD: Makefile,v 1.33 2012/10/25 06:55:50 asau Exp $
#
# Note: we currently use the pre-built (-bin) distribution of FOP,
#

DISTNAME=	fop-${VERSION}-bin
PKGNAME=	fop-${VERSION}
VERSION=	1.0
CATEGORIES=	textproc www
MASTER_SITES=	${MASTER_SITE_APACHE:=xmlgraphics/fop/binaries/}

MAINTAINER=	ftigeot@users.sourceforge.net
HOMEPAGE=	http://xmlgraphics.apache.org/fop/
COMMENT=	Print formatter driven by XSL Formatting Objects (XSL-FO)
LICENSE=	apache-2.0

USE_JAVA=	run
USE_TOOLS+=	pax
NO_CONFIGURE=	yes
NO_BUILD=	yes
INSTALLATION_DIRS=	bin share/java/fop

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

PLIST_SRC=	${PKGDIR}/PLIST

SUBST_CLASSES+=			java_home
SUBST_STAGE.java_home=		post-patch
SUBST_MESSAGE.java_home=	Setting JAVA_HOME to a sane value.
SUBST_FILES.java_home=		fop
SUBST_SED.java_home=		-e 's,@JAVA_HOME@,${PKG_JAVA_HOME},g'

.include "options.mk"

do-install:
	cd ${WRKSRC} && ${PAX} -rw . ${DESTDIR}${PREFIX}/share/java/fop
	${LN} -sf ../share/java/fop/fop ${DESTDIR}${PREFIX}/bin
	${RM} -f ${DESTDIR}${PREFIX}/share/java/fop/fop.orig

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
