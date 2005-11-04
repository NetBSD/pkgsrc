# $NetBSD: Makefile,v 1.66 2005/11/04 21:21:02 tonio Exp $
#

.include "Makefile.common"

PKGREVISION=		1

CONFLICTS+=		kaffe-nox11-[0-9]*

JAVA_WRAPPERS=		appletviewer jar java javac javadoc javah javakey \
			javap jdb rmic rmiregistry serialver

CONF_FILES=		${JAVA_HOME}/jre/lib/security/java.security.default \
			${JAVA_HOME}/jre/lib/security/java.security

.include "../../mk/bsd.prefs.mk"

UNLIMIT_RESOURCES=        datasize
LIBS+= -lltdl

PRINT_PLIST_AWK+=	/^java\/kaffe\/jre\/lib\/security\/java.security$$/ \
				{ next; }

post-install:
	${INSTALL_DATA} ${WRKSRC}/license.terms ${JAVA_HOME}

.include "../../devel/libltdl/buildlink3.mk"
.include "../../mk/java-env.mk"
.include "../../mk/bsd.pkg.mk"
