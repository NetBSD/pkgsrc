# $NetBSD: Makefile,v 1.7 2021/03/29 06:28:43 nia Exp $
#

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

MAVEN_OPTS+=	-Duser.home=${FAKEHOMEDIR}
#MAVEN_OPTS+=	-Dmaven.repo.local=${WRKDIR}/deps
#MAVEN_OPTS+=	--offline

PKG_JVMS_ACCEPTED=	openjdk8

.include "../../devel/mk-configure/mk-c.mk"
.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
