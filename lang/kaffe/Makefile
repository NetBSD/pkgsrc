# $NetBSD: Makefile,v 1.58 2005/01/30 23:18:38 jmmv Exp $
#

.include "Makefile.common"

PKGREVISION=		6

CONFLICTS+=		kaffe-nox11-[0-9]*

JAVA_WRAPPERS=		appletviewer jar java javac javadoc javah javakey \
			javap jdb rmic rmiregistry serialver

SUPPORT_FILES=		${JAVA_HOME}/jre/lib/security/java.security.default \
			${JAVA_HOME}/jre/lib/security/java.security

.include "../../mk/bsd.prefs.mk"

PRINT_PLIST_AWK+=	/^java\/kaffe\/jre\/lib\/security\/java.security$$/ \
				{ next; }

post-install:
	${INSTALL_DATA} ${WRKSRC}/license.terms ${JAVA_HOME}

.include "../../devel/libltdl/convenience.mk"
.include "../../mk/java-env.mk"
.include "../../mk/bsd.pkg.mk"
