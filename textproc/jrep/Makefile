# $NetBSD: Makefile,v 1.8 2025/04/07 10:08:39 wiz Exp $

DISTNAME=	jrep-1.1.0
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=cheusov/}
GITHUB_PROJECT=	jrep

MAINTAINER=	cheusov@NetBSD.org
HOMEPAGE=	https://github.com/cheusov/jrep
COMMENT=	Command-line grep-like utility written in Java

TOOL_DEPENDS+=	apache-maven-[0-9]*:../../devel/apache-maven
SUPERSEDES+=	jgrep-[0-9]*

LICENSE=	apache-2.0

USE_LANGUAGES=	c
USE_JAVA=	yes
USE_TOOLS+=	pod2man

TEST_TARGET=	test

MAKE_ENV+=	MANDIR=${PREFIX}/${PKGMANDIR} MAVEN_OPTS=${MAVEN_OPTS:Q}

# TODO: this downloads files during the build
# [ERROR] Plugin org.apache.maven.plugins:maven-resources-plugin:2.6 or one of its dependencies could not be resolved: Failed to read artifact descriptor for org.apache.maven.plugins:maven-resources-plugin:jar:2.6: Could not transfer artifact org.apache.maven.plugins:maven-resources-plugin:pom:2.6 from/to central (https://repo.maven.apache.org/maven2): transfer failed for https://repo.maven.apache.org/maven2/org/apache/maven/plugins/maven-resources-plugin/2.6/maven-resources-plugin-2.6.pom: Network is unreachable (connect failed) -> [Help 1]

MAVEN_OPTS+=	-Duser.home=${FAKEHOMEDIR}
#MAVEN_OPTS+=	-Dmaven.repo.local=${WRKDIR}/deps
#MAVEN_OPTS+=	--offline

PKG_JVMS_ACCEPTED=	openjdk8

.include "../../devel/mk-configure/mk-c.mk"
.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
