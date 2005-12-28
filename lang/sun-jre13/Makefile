# $NetBSD: Makefile,v 1.43 2005/12/28 09:21:57 abs Exp $

DISTNAME=	j2re-1_3_1_17-linux-i586
PKGNAME=	sun-jre13-1.0.17
MASTER_SITES=	# empty

COMMENT=	Sun's Java(tm) Runtime Environment 1.3.1

SHORT=		JRE

JAVA_WRAPPERS=	java keytool policytool rmid rmiregistry tnameserv
WRKSRC=		${WRKDIR}/jre1.3.1_17
USE_PKGINSTALL=	yes
OWN_DIRS=	${JAVA_HOME}
OWN_DIRS+=	${JAVA_HOME}/lib
OWN_DIRS+=	${JAVA_HOME}/lib/images
OWN_DIRS+=	${JAVA_HOME}/lib/images/cursors
OWN_DIRS+=	${JAVA_HOME}/lib/security
SFILES=		content-types.properties	flavormap.properties
SFILES+=	font.properties		font.properties.ja
SFILES+=	font.properties.zh	images/cursors/cursors.properties
SFILES+=	jvm.cfg			psfont.properties.ja
SFILES+=	psfontj2d.properties	security/java.security
CONF_FILES=	# empty
.for FILE in ${SFILES}
CONF_FILES+=	${JAVA_HOME}/lib/${FILE}.default ${JAVA_HOME}/lib/${FILE}
.endfor

do-configure:
	cd ${WRKSRC}/lib; for file in ${SFILES}; do			\
		${MV} -f $$file $$file.default;				\
	done

.include "../../lang/sun-jre13/Makefile.common"
