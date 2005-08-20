# $NetBSD: Makefile,v 1.60 2005/08/20 19:16:23 jlam Exp $
#

.include "Makefile.common"

PKGREVISION=		7

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

.include "../../devel/libltdl/convenience.mk"
.include "../../mk/java-env.mk"
.include "../../mk/bsd.pkg.mk"
