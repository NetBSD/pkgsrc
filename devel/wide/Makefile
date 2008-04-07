# $NetBSD: Makefile,v 1.8 2008/04/07 16:18:02 joerg Exp $
#

DISTNAME=		wide
PKGNAME=		wide-0.1
PKGREVISION=		2
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

post-extract:
	chmod -R go-w ${WRKSRC}

do-configure:
	${SED} -e 's|@PREFIX@|${PREFIX}|g' ${FILESDIR}/wide.in > ${WRKSRC}/wide
	${RM} -fr ${WRKSRC}/images/Copy*

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/wide ${DESTDIR}${PREFIX}/bin/wide
	cd ${WRKSRC} && ${PAX} -rw Study etc help images *.ini *.xml version.txt \
				${DESTDIR}${PREFIX}/share/wide/
	cd ${WRKSRC} && ${PAX} -rw lib ${DESTDIR}${PREFIX}/libexec/wide/

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
