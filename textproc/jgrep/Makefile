# $NetBSD: Makefile,v 1.6 2016/05/28 15:11:30 cheusov Exp $
#

DISTNAME=	jgrep-0.5.2
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=cheusov/}
GITHUB_PROJECT= jgrep
#GITHUB_RELEASE= ${DISTNAME}

MAINTAINER=	cheusov@NetBSD.org
HOMEPAGE=	https://github.com/cheusov/jgrep
COMMENT=	Command-line grep-like utility written in Java

TOOL_DEPENDS+=	apache-maven-[0-9]*:../../devel/apache-maven

LICENSE=	apache-2.0

USE_LANGUAGES=	c
USE_JAVA=	yes

TEST_TARGET=	test

MAKE_ENV+=	MANDIR=${PREFIX}/${PKGMANDIR}

MAVEN_FLAGS+=	-Duser.home=${FAKEHOMEDIR}
MAVEN_FLAGS+=	-Dmaven.repo.local=${WRKDIR}/deps
MAVEN_FLAGS+=	--offline

.include "../../devel/mk-configure/mk-c.mk"
.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
