# $NetBSD: Makefile,v 1.6 2024/05/29 16:31:58 adam Exp $

# Java project does not work as follows:
# Error: could not find libjava.so
# Error: Could not find Java SE Runtime Environment.

# To bootstrap Bezel, apply all patches and run as do-build target
# defines under Linux.

.if UPSTREAM
DISTNAME=	bazel-6.4.0-dist
PKGNAME=	${DISTNAME:S/-dist//}
PKGREVISION=	1
MASTER_SITES=	${MASTER_SITE_GITHUB:=bazelbuild/}
GITHUB_PROJECT=	bazel
GITHUB_RELEASE= ${PKGVERSION_NOREV}
EXTRACT_SUFX=	.zip
.else
DISTNAME=	bazel-6.4.0-dist-netbsd
PKGNAME=	${DISTNAME:S/-dist-netbsd//}
MASTER_SITES=	${MASTER_SITE_LOCAL}
.endif
CATEGORIES=	devel

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://bazel.build/
COMMENT=	Fast and correct build automation tool
LICENSE=	apache-2.0

BROKEN_ON_PLATFORM=	${LP32PLATFORMS}

WRKSRC=		${WRKDIR}
USE_TOOLS+=	bash pkg-config unzip zip
USE_LANGUAGES=	c c++

CHECK_PIE_SUPPORTED=	no

USE_JAVA=		yes
USE_JAVA2=		11
PKG_JVMS_ACCEPTED=	openjdk11

REPLACE_BASH+=	*.sh
REPLACE_BASH+=	scripts/*.sh
REPLACE_BASH+=	tools/*.sh
REPLACE_BASH+=	tools/*/*.sh

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_MESSAGE.prefix=	Setting PREFIX
SUBST_FILES.prefix+=	tools/cpp/bsd_cc_toolchain_config.bzl
SUBST_VARS.prefix+=	PREFIX

EXTRA_BAZEL_ARGS+=	--tool_java_runtime_version=local_jdk
EXTRA_BAZEL_ARGS+=	--subcommands
MAKE_ENV+=		EXTRA_BAZEL_ARGS=${EXTRA_BAZEL_ARGS:Q}

INSTALLATION_DIRS+=	bin

do-patch:
	# Do not perform patching. The tarball includes all patches.

pre-configure:
	${FIND} ${WRKSRC} | ${GREP} '\.orig$$' | xargs ${RM}
	# Do not use wrapped toolchain after installation
	${RM} -r ${WRKDIR}/.cwrapper

do-build:
	cd ${WRKSRC} \
	&& env ${MAKE_ENV} \
		${BASH} ./compile.sh

do-install:
	# Do not strip bazel binary. It includes .zip archive.
	${INSTALL_SCRIPT} ${WRKSRC}/output/bazel \
		${DESTDIR}${PREFIX}/bin

# GCC generates unexpected .d files when -MD is specified.
.include "../../lang/clang/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
