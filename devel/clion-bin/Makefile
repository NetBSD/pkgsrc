# $NetBSD: Makefile,v 1.9 2025/08/21 00:25:45 schmonz Exp $

VERSION=		2025.2
JB_SUFX=		# empty
.if ${MACHINE_ARCH} == "aarch64"
JB_SUFX=		-aarch64
.endif
DISTNAME=		CLion-${VERSION:S/.0.0//}${JB_SUFX}
PKGNAME=		clion-bin-${VERSION}
CATEGORIES=		devel
MASTER_SITES=		https://download.jetbrains.com/cpp/

MAINTAINER=		youri@NetBSD.org
HOMEPAGE=		https://www.jetbrains.com/clion/
COMMENT=		JetBrains C/C++ IDE
LICENSE=		apache-2.0

DEPENDS+=		intellij-fsnotifier-[0-9]*:../../sysutils/intellij-fsnotifier

WRKSRC=			${WRKDIR}/clion-${VERSION}
USE_JAVA2=		17

USE_TOOLS+=		bash:run pax sed

REPLACE_BASH+=		plugins/clion-radler/tools/profiler/dotTrace.sh \
			plugins/terminal/shell-integrations/bash/bash-integration.bash

CHECK_INTERPRETER_SKIP=	${PKGBASE}/plugins/tailwindcss/server/tailwindcss-language-server \
			${PKGBASE}/plugins/vuejs/vue-language-server/bin/vue-language-server.js \
			${PKGBASE}/plugins/nodeJS/js/ts-file-loader/node_modules/tsx/dist/cli.mjs \
			${PKGBASE}/plugins/nodeJS/js/ts-file-loader/node_modules/esbuild/bin/esbuild \
			${PKGBASE}/plugins/javascript-plugin/helpers/package-version-range-matcher/node_modules/semver/bin/semver.js

CHECK_SHLIBS_SKIP=	*
CHECK_RELRO_SUPPORTED=	no
CHECK_PIE_SUPPORTED=	no

INSTALLATION_DIRS=	${PKGBASE} \
			share/applications

SUBST_CLASSES+=		jdk
SUBST_STAGE.jdk=	pre-install
SUBST_FILES.jdk=	bin/clion.sh
SUBST_VARS.jdk=		PKG_JAVA_HOME

SUBST_CLASSES+=		vmoptions
SUBST_STAGE.vmoptions=	pre-configure
SUBST_FILES.vmoptions=	bin/clion64.vmoptions
SUBST_SED.vmoptions=	-e 's|^-Xmx.*|-Xmx4096m|'
SUBST_SED.vmoptions+=	-e 's|^-Xms.*|-Xms4096m|'

PLIST_VARS+=		aarch64 x86_64
.if ${MACHINE_ARCH} == "aarch64"
PLIST.aarch64=		yes
.else
PLIST.x86_64=		yes
.endif

pre-configure:
	cd ${WRKSRC} &&	\
	${RM} -rf bin/*.orig \
		bin/clang \
		bin/fsnotifier \
		bin/cmake \
		bin/gdb \
		plugins/python-ce \
		plugins/performanceTesting \
		plugins/cwm-plugin \
		jbr/lib \
		jbr/bin \
		bin/lldb

post-configure:
	${SED} -e "s|@@IDEA_HOME@@|${PREFIX}/${PKGBASE}|g" \
	    < ${FILESDIR}/clion.desktop \
	    > ${WRKDIR}/clion.desktop

do-build:
	${ECHO} "-XX:-UseCompressedClassPointers" \
	    >> ${WRKSRC}/bin/clion64.vmoptions
	${ECHO} "-XX:-UseCompressedOops" \
	    >> ${WRKSRC}/bin/clion64.vmoptions
	${ECHO} "idea.filewatcher.executable.path=${PREFIX}/bin/fsnotifier" \
	    >> ${WRKSRC}/bin/idea.properties
	# https://youtrack.jetbrains.com/issue/IDEA-323750
	${ECHO} "idea.ui.icons.svg.disk.cache=false" \
	    >> ${WRKSRC}/bin/idea.properties

do-install:
	${INSTALL_DATA} ${WRKDIR}/clion.desktop \
	    ${DESTDIR}${PREFIX}/share/applications/
	cd ${WRKSRC} &&	pax -rw -pm -s ',.*\.orig,,' \
	    * ${DESTDIR}${PREFIX}/${PKGBASE}

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
