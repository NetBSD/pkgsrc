# $NetBSD: Makefile,v 1.1.1.1 2003/03/19 16:09:29 jschauma Exp $
#

DISTNAME=	${PKGNAME}
PKGNAME=	eclipse-2.0.2
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.netbsd.org/pub/NetBSD/misc/jschauma/

MAINTAINER=	jschauma@netbsd.org
HOMEPAGE=	http://www.eclipse.org
COMMENT=	Java IDE

DEPENDS+=	jakarta-ant>=1.4.1:../../devel/jakarta-ant

PKG_JVM=	sun-jdk13

MAKE_ENV+=	JAVA_HOME=${PKG_JAVA_HOME}
MAKE_ENV+=	ANT_HOME=${PREFIX}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Linux"
DISTNAME=	eclipse-sourceBuild-srcIncluded-2.0.2
MASTER_SITES=	http://download.eclipse.org/downloads/drops/R-2.0.2-200211071448/
EXTRACT_SUFX=	.zip

PAXDIR=		${WRKDIR}

do-build:
	cd ${WRKDIR} && ${MAKE_ENV} ${SH} build -os linux -ws motif
.else
NO_BUILD=	#defined
PAXDIR=		${WRKSRC}
.endif

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/eclipse
	cd ${PAXDIR} && ${PAX} -s ,^./[.].*,, -rw . ${PREFIX}/eclipse/
	${SED} -e "s,@PREFIX@,${PREFIX}," ${FILESDIR}/eclipse > 	\
			${WRKDIR}/.eclipse
	${INSTALL_SCRIPT} ${WRKDIR}/.eclipse ${PREFIX}/bin/eclipse

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
