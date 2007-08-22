# $NetBSD: Makefile,v 1.50 2007/08/22 14:03:48 jlam Exp $

DISTNAME=	j2re-1_3_1_19-linux-${DIST_ARCH}
PKGNAME=	sun-jre13-1.0.19
PKGREVISION=	1
MASTER_SITES=	# empty

COMMENT=	Sun's Java(tm) Runtime Environment 1.3.1

SHORT=		JRE

WRKSRC=		${WRKDIR}/jre1.3.1_19
JAVA_WRAPPERS=	java keytool policytool rmid rmiregistry tnameserv

.include "../../lang/sun-jre13/Makefile.common"

REQD_DIRS=	${JAVA_HOME}
REQD_DIRS+=	${JAVA_HOME}/lib
REQD_DIRS+=	${JAVA_HOME}/lib/images
REQD_DIRS+=	${JAVA_HOME}/lib/images/cursors
REQD_DIRS+=	${JAVA_HOME}/lib/security
SFILES=		content-types.properties	flavormap.properties
SFILES+=	font.properties		font.properties.ja
SFILES+=	font.properties.zh	images/cursors/cursors.properties
SFILES+=	jvm.cfg			psfont.properties.ja
SFILES+=	psfontj2d.properties	security/java.security
CONF_FILES=	# empty
.for FILE in ${SFILES}
CONF_FILES+=	${JAVA_HOME}/lib/${FILE}.default ${JAVA_HOME}/lib/${FILE}
.endfor

# Some binary files cannot resolve their libraries. This doesn't matter
# since they will only be called through wrappers.
CHECK_SHLIBS_SUPPORTED=	no

post-extract:
	chmod -R go-w ${WRKSRC}

do-configure:
	cd ${WRKSRC}/lib; for file in ${SFILES}; do			\
		${MV} -f $$file $$file.default;				\
	done

.include "../../mk/bsd.pkg.mk"
