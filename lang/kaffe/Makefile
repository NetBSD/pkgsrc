# $NetBSD: Makefile,v 1.63 2005/09/06 19:11:24 tonio Exp $
#

.include "Makefile.common"

CONFLICTS+=		kaffe-nox11-[0-9]*

JAVA_WRAPPERS=		appletviewer jar java javac javadoc javah javakey \
			javap jdb rmic rmiregistry serialver

CONF_FILES=		${JAVA_HOME}/jre/lib/security/java.security.default \
			${JAVA_HOME}/jre/lib/security/java.security

.include "../../mk/bsd.prefs.mk"

PRINT_PLIST_AWK+=	/^java\/kaffe\/jre\/lib\/security\/java.security$$/ \
				{ next; }

post-install:
	${INSTALL_DATA} ${WRKSRC}/license.terms ${JAVA_HOME}

.include "../../devel/libltdl/buildlink3.mk"
.include "../../mk/java-env.mk"
.include "../../mk/bsd.pkg.mk"
