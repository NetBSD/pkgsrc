# $NetBSD: Makefile,v 1.12 2004/10/11 14:02:23 abs Exp $
#

DISTNAME=	${PKGNAME}
PKGNAME=	eclipse-${VERSION}
CATEGORIES=	devel java
MASTER_SITES=	ftp://ftp.NetBSD.org/pub/NetBSD/misc/jschauma/
EXTRACT_SUFX=	.zip

MAINTAINER=	jschauma@NetBSD.org
HOMEPAGE=	http://www.eclipse.org/
COMMENT=	Java IDE

DEPENDS+=	apache-ant>=1.4.1:../../devel/apache-ant

PKG_JVMS_ACCEPTED= sun-jdk15 sun-jdk14

MAKE_ENV+=	JAVA_HOME=${PKG_JAVA_HOME}
MAKE_ENV+=	ANT_HOME=${PREFIX}

VERSION=	3.0

# XXX: Others might work but might need significant tweaking
ONLY_FOR_PLATFORM=	NetBSD-*-i386 Linux-*-*

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Linux"
DISTNAME=	eclipse-sourceBuild-srcIncluded-${VERSION}
MASTER_SITES=	ftp://download.eclipse.org/R-3.0-200406251208/

BUILD_DEPENDS+=	zip>=2.3:../../archivers/zip

PAXDIR=		${WRKDIR}

do-build:
	cd ${WRKDIR} && ${MAKE_ENV} ${SH} build -os linux -ws motif -arch x86
.else
NO_BUILD=	#defined
PAXDIR=		${WRKSRC}
CHECK_SHLIBS=	NO

do-extract:
	${MKDIR} ${WRKDIR}/result
	${CP} ${DISTDIR}/${PKGNAME}${EXTRACT_SUFX} ${WRKDIR}/result/linux-motif-x86-sdk.zip
.endif

post-build:
	${RM} -fr ${WRKDIR}/tmp

do-install:
	cd  ${PREFIX} && unzip ${WRKDIR}/result/linux-motif-x86-sdk.zip
	${SED} -e "s,@PREFIX@,${PREFIX}," ${FILESDIR}/eclipse > 	\
			${WRKDIR}/.eclipse
	${INSTALL_SCRIPT} ${WRKDIR}/.eclipse ${PREFIX}/bin/eclipse

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
