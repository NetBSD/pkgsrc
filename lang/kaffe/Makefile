# $NetBSD: Makefile,v 1.54 2004/07/04 15:24:46 jmmv Exp $
#

.include "Makefile.common"

PKGREVISION=		2

CONFLICTS+=		kaffe-nox11-[0-9]*

JAVA_WRAPPERS=		appletviewer jar java javac javadoc javah javap

SUPPORT_FILES=		${JAVA_HOME}/jre/lib/security/java.security.default \
			${JAVA_HOME}/jre/lib/security/java.security

.include "../../mk/bsd.prefs.mk"

PRINT_PLIST_AWK+=	/^java\/kaffe\/jre\/lib\/security\/java.security$$/ \
				{ next; }

post-install:
	${INSTALL_DATA} ${WRKSRC}/license.terms ${JAVA_HOME}

.include "../../mk/java-env.mk"
.include "../../mk/bsd.pkg.mk"
