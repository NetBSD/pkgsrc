# $NetBSD: Makefile,v 1.2 2005/02/01 19:15:28 jschauma Exp $
#

DISTNAME=		wide
PKGNAME=		wide-0.1
CATEGORIES=		devel lang
MASTER_SITES=		http://www2.mta.ac.il/~tal/WIDE/
EXTRACT_SUFX=		.zip

MAINTAINER=		jschauma@NetBSD.org
HOMEPAGE=		http://www2.mta.ac.il/~tal/WIDE/
COMMENT=		IDE for the While programming language

NO_BUILD=		yes
WRKSRC=			${WRKDIR}/${DISTNAME:tu}
EXTRACT_CMD_OPTS.zip=	-aqo

LICENSE=		eclipse-license

PKG_JVMS_ACCEPTED=	sun-jdk14 sun-jdk15

do-configure:
	${SED} -e 's|@PREFIX@|${PREFIX}|g' ${FILESDIR}/wide.in > ${WRKSRC}/wide
	${RM} -fr ${WRKSRC}/images/Copy*

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/wide
	${INSTALL_DATA_DIR} ${PREFIX}/libexec/wide
	${INSTALL_SCRIPT} ${WRKSRC}/wide ${PREFIX}/bin/wide
	cd ${WRKSRC} && ${PAX} -rw Study etc help images *.ini *.xml version.txt \
				${PREFIX}/share/wide/
	cd ${WRKSRC} && ${PAX} -rw lib ${PREFIX}/libexec/wide/

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
