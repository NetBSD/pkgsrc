# $NetBSD: Makefile,v 1.1 2016/03/01 20:45:31 jmmv Exp $

DISTNAME=	bazel-0.2.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=bazelbuild/}

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://bazel.io/
COMMENT=	Google's own build tool
LICENSE=	apache-2.0

DEPENDS+=		unzip-[0-9]*:../../archivers/unzip
DEPENDS+=		zip-[0-9]*:../../archivers/zip

ONLY_FOR_PLATFORM=	Darwin-*-* Linux-*-*

USE_JAVA=		yes
USE_LANGUAGES=		c++
USE_TOOLS=		pkg-config
PKG_JVMS_ACCEPTED=	openjdk7 openjdk8 sun-jdk7 oracle-jdk8

SUBST_CLASSES+=		conf
SUBST_FILES.conf=	src/main/cpp/blaze_startup_options.cc
SUBST_MESSAGE.conf=	Set path to system-wide bazel.bazelrc
SUBST_STAGE.conf=	pre-configure
SUBST_SED.conf=		-e s,/etc/bazel.bazelrc,${PKG_SYSCONFDIR}/bazel.bazelrc,g

SUBST_CLASSES+=		tools
SUBST_FILES.tools=	src/main/java/com/google/devtools/build/lib/rules/objc/CompilationSupport.java
SUBST_FILES.tools+=	src/main/java/com/google/devtools/build/lib/rules/objc/ReleaseBundlingSupport.java
SUBST_FILES.tools+=	tools/build_defs/d/d.bzl
SUBST_FILES.tools+=	tools/build_rules/py_rules.bzl
SUBST_FILES.tools+=	tools/build_rules/rust/rust.bzl
SUBST_MESSAGE.tools=	Set path to tools
SUBST_STAGE.tools=	pre-configure
SUBST_SED.tools=	-e s,/usr/bin/unzip,${PREFIX}/bin/unzip,g
SUBST_SED.tools+=	-e s,/usr/bin/zip,${PREFIX}/bin/zip,g

INSTALLATION_DIRS=	bin

do-build:
	cd ${WRKSRC} && ./compile.sh

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/output/bazel ${DESTDIR}${PREFIX}/bin/bazel

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
