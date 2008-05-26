# $NetBSD: Makefile,v 1.10 2008/05/26 02:13:18 joerg Exp $
#

DISTNAME=		wide
PKGNAME=		wide-0.1
PKGREVISION=		3
CATEGORIES=		devel lang
MASTER_SITES=		http://www2.mta.ac.il/~tal/WIDE/
EXTRACT_SUFX=		.zip

MAINTAINER=		jschauma@NetBSD.org
HOMEPAGE=		http://www2.mta.ac.il/~tal/WIDE/
COMMENT=		IDE for the While programming language

PKG_DESTDIR_SUPPORT=	user-destdir

NO_BUILD=		yes
WRKSRC=			${WRKDIR}/WIDE
EXTRACT_OPTS_ZIP=	-aqo

LICENSE=		eclipse-license

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
