# $NetBSD: Makefile,v 1.27 2009/12/24 03:49:35 dsainty Exp $
#

DISTNAME=	${PKGNAME_NOREV}
PKGNAME=	eclipse-${VERSION}
PKGREVISION=	2
CATEGORIES=	devel java
MASTER_SITES=	ftp://ftp.NetBSD.org/pub/NetBSD/misc/jschauma/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.eclipse.org/
COMMENT=	Java IDE
LICENSE=	eclipse-license

DEPENDS+=	apache-ant>=1.4.1:../../devel/apache-ant
USE_TOOLS+=	unzip

PKG_DESTDIR_SUPPORT=	user-destdir

PKG_JVMS_ACCEPTED= sun-jdk6 sun-jdk15 sun-jdk14

MAKE_ENV+=	JAVA_HOME=${PKG_JAVA_HOME:Q}
MAKE_ENV+=	ANT_HOME=${PREFIX:Q}

VERSION=	3.0.1

# XXX: Others might work but might need significant tweaking
ONLY_FOR_PLATFORM=	NetBSD-*-i386 NetBSD-*-x86_64 Linux-*-*

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Linux"
DISTNAME=	eclipse-sourceBuild-srcIncluded-${VERSION}
MASTER_SITES=	ftp://download.eclipse.org/R-3.0.1-200409161125/

BUILD_DEPENDS+=	zip>=2.3:../../archivers/zip

INSTALLATION_DIRS=	bin

do-build:
	cd ${WRKDIR} && ${MAKE_ENV} ${SH} build -os linux -ws motif -arch x86
.else
NO_BUILD=		yes
CHECK_SHLIBS_SUPPORTED=	no

do-extract:
	${MKDIR} ${WRKDIR}/result
	${CP} ${DISTDIR}/${PKGNAME_NOREV}${EXTRACT_SUFX} ${WRKDIR}/result/linux-motif-x86-sdk.zip
.endif

post-build:
	${RM} -fr ${WRKDIR}/tmp

do-install:
	cd ${DESTDIR}${PREFIX} && \
		unzip ${WRKDIR}/result/linux-motif-x86-sdk.zip
	${SED} -e "s,@PREFIX@,${PREFIX}," ${FILESDIR}/eclipse > 	\
		${WRKDIR}/.eclipse
	${INSTALL_SCRIPT} ${WRKDIR}/.eclipse ${DESTDIR}${PREFIX}/bin/eclipse

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
