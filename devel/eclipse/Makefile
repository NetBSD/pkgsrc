# $NetBSD: Makefile,v 1.8 2003/12/30 17:21:55 cjep Exp $
#

DISTNAME=	${PKGNAME}
PKGNAME=	eclipse-2.1
CATEGORIES=	devel java
MASTER_SITES=	ftp://ftp.NetBSD.org/pub/NetBSD/misc/jschauma/

MAINTAINER=	jschauma@NetBSD.org
HOMEPAGE=	http://www.eclipse.org/
COMMENT=	Java IDE

DEPENDS+=	apache-ant>=1.4.1:../../devel/apache-ant

PKG_JVM=	sun-jdk14

MAKE_ENV+=	JAVA_HOME=${PKG_JAVA_HOME}
MAKE_ENV+=	ANT_HOME=${PREFIX}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Linux"
DISTNAME=	eclipse-sourceBuild-srcIncluded-2.1
MASTER_SITES=	http://download.eclipse.org/downloads/drops/R-2.1-200303272130/
EXTRACT_SUFX=	.zip

PAXDIR=		${WRKDIR}

do-build:
	cd ${WRKDIR} && ${MAKE_ENV} ${SH} build -os linux -ws motif
.else
NO_BUILD=	#defined
PAXDIR=		${WRKSRC}
CHECK_SHLIBS=	NO
.endif

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/eclipse
	cd ${PAXDIR} && ${PAX} -s ,^./[.].*,, -rw . ${PREFIX}/eclipse/
	${SED} -e "s,@PREFIX@,${PREFIX}," ${FILESDIR}/eclipse > 	\
			${WRKDIR}/.eclipse
	${INSTALL_SCRIPT} ${WRKDIR}/.eclipse ${PREFIX}/bin/eclipse

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
