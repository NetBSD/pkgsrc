# $NetBSD: Makefile,v 1.15 2012/10/31 11:19:53 asau Exp $
#

DISTNAME=		wide
PKGNAME=		wide-0.1
PKGREVISION=		3
CATEGORIES=		devel lang
MASTER_SITES=		http://www2.mta.ac.il/~tal/WIDE/
EXTRACT_SUFX=		.zip

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www2.mta.ac.il/~tal/WIDE/
COMMENT=		IDE for the While programming language
LICENSE=		eclipse-license

NO_BUILD=		yes
WRKSRC=			${WRKDIR}/WIDE

PKG_JVMS_ACCEPTED=	sun-jdk14 sun-jdk15

INSTALLATION_DIRS=	bin libexec/wide share/wide

USE_TOOLS+=		pax:run

post-extract:
	chmod -R go-w ${WRKSRC}

do-configure:
	${SED} -e 's|@PAX@|${PAX}|' -e 's|@PREFIX@|${PREFIX}|g' ${FILESDIR}/wide.in > ${WRKSRC}/wide
	${RM} -fr ${WRKSRC}/images/Copy*

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/wide ${DESTDIR}${PREFIX}/bin/wide
	cd ${WRKSRC} && pax -rw Study etc help images *.ini *.xml version.txt \
				${DESTDIR}${PREFIX}/share/wide/
	cd ${WRKSRC} && pax -rw lib ${DESTDIR}${PREFIX}/libexec/wide/

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
