# $NetBSD: Makefile,v 1.31 2004/01/02 17:07:21 jschauma Exp $

DISTNAME=	j2re-1_3_1_10-linux-i586
PKGNAME=	sun-jre13-1.0.10
WRKSRC=		${WRKDIR}/jre1.3.1_10
MASTER_SITES=	# empty

COMMENT=	Sun's Java(tm) Runtime Environment 1.3.1

SHORT=		JRE

USE_PKGINSTALL=	yes
OWN_DIRS=	${PREFIX}
OWN_DIRS+=	${PREFIX}/lib
OWN_DIRS+=	${PREFIX}/lib/images
OWN_DIRS+=	${PREFIX}/lib/images/cursors
OWN_DIRS+=	${PREFIX}/lib/security
SFILES=		content-types.properties	flavormap.properties
SFILES+=	font.properties		font.properties.ja
SFILES+=	font.properties.zh	images/cursors/cursors.properties
SFILES+=	jvm.cfg			psfont.properties.ja
SFILES+=	psfontj2d.properties	security/java.security
SUPPORT_FILES=	# empty
.for FILE in ${SFILES}
SUPPORT_FILES+=	${PREFIX}/lib/${FILE}.default ${PREFIX}/lib/${FILE}
.endfor

do-configure:
	cd ${WRKSRC}/lib; for file in ${SFILES}; do			\
		${MV} -f $$file $$file.default;				\
	done

.include "../../lang/sun-jre13/Makefile.common"

PREFIX=		${JVM_HOME}
