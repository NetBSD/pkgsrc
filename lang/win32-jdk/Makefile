# $NetBSD: Makefile,v 1.1.1.1 2004/10/11 13:37:10 tv Exp $
#
# Interix-only "JDK" for pkgsrc, implemented as a script wrapper around the
# Win32 Sun JDK/JRE.
#

DISTNAME=		win32-jdk-0.1
CATEGORIES=		lang java
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		tv@duh.org
HOMEPAGE=		http://www.java.com/
COMMENT=		Interix wrapper package for Win32 Sun Java(tm) 2

WRKSRC=			${WRKDIR}
EXTRACT_ONLY=		# empty
USE_LANGUAGES=		# empty
NO_CHECKSUM=		yes

USE_PKGINSTALL=		yes
OWN_DIRS=		${JAVA_HOME}

ONLY_FOR_PLATFORM=	Interix-*-*

JAVA_NAME=		win32
JAVA_HOME=		${LOCALBASE}/java/win32
NO_MTREE=		yes	# since we change PREFIX below

JAVA_WRAPPERS=		appletviewer extcheck idlj jar jarsigner \
			java javac javadoc javah javap jdb keytool \
			orbd policytool rmic serialver rmid \
			rmiregistry servertool tnameserv

JAVA_EXTRA=		HtmlConverter kinit klist ktab native2ascii

do-build:

do-install:
	${INSTALL_SCRIPT_DIR} ${JAVA_HOME}/bin
	${INSTALL_SCRIPT} ${FILESDIR}/java.sh ${JAVA_HOME}/bin/java
	${LN} -sf . ${JAVA_HOME}/jre
.for f in ${JAVA_WRAPPERS:Njava} ${JAVA_EXTRA}
	${LN} -sf java ${JAVA_HOME}/bin/$f
.endfor

.include "../../mk/java-env.mk"
.include "../../mk/bsd.pkg.mk"
