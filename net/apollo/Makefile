# $NetBSD: Makefile,v 1.2 2012/10/23 17:18:09 asau Exp $
#

APOLLOVERS=	1.4
DISTNAME=	apache-apollo-${APOLLOVERS}-unix-distro
PKGNAME=	apollo-${APOLLOVERS}
CATEGORIES=	net java
MASTER_SITES=	${MASTER_SITE_APACHE:=activemq/activemq-apollo/1.4/}

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	http://activemq.apache.org/apollo/
COMMENT=	Messaging broker built from the foundations of ActiveMQ
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}/apache-apollo-1.4

USE_JAVA=	run
NO_BUILD=	yes
USE_TOOLS+=	pax

EGDIR=		share/examples/apollo

INSTALLATION_DIRS=	bin lib/apollo ${EGDIR} ${PKG_SYSCONFDIR}/apollo

CONF_FILES=		${PREFIX}/${EGDIR}/jul.properties	\
			${PKG_SYSCONFDIR}/apollo/jul.properties

SUBST_CLASSES+=		home
SUBST_FILES.home=	${WRKSRC}/bin/apollo
SUBST_SED.home=		-e 's,@APOLLO_HOME@,${PREFIX},'
SUBST_SED.home+=	-e 's,@JAVA_HOME@,${PKG_JAVA_HOME},'
SUBST_STAGE.home=	post-patch

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/apollo ${DESTDIR}${PREFIX}/bin

	${INSTALL_DATA} ${WRKSRC}/etc/jul.properties	\
		${DESTDIR}${PREFIX}/${EGDIR}

	cd ${WRKSRC}/lib && ${PAX} -wr * ${DESTDIR}${PREFIX}/lib/apollo
	${CHMOD} ${SHAREMODE} ${DESTDIR}${PREFIX}/lib/apollo/*.jar

	cd ${WRKSRC}/examples && ${PAX} -wr * ${DESTDIR}${PREFIX}/${EGDIR}
	${FIND} ${DESTDIR}${PREFIX}/${EGDIR} -type f -print |	\
		${XARGS} ${CHMOD} ${SHAREMODE}

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
