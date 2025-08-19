# $NetBSD: Makefile,v 1.12 2025/08/19 03:58:45 schmonz Exp $

VERSION=		2025.2
JB_SUFX=		# empty
.if ${MACHINE_ARCH} == "aarch64"
JB_SUFX=		-aarch64
.endif
DISTNAME=		ideaIU-${VERSION:S/.0.0//}${JB_SUFX}
PKGNAME=		intellij-ue-bin-${VERSION}
CATEGORIES=		devel
MASTER_SITES=		https://download.jetbrains.com/idea/

MAINTAINER=		youri@NetBSD.org
HOMEPAGE=		https://www.jetbrains.com/opensource/idea/
COMMENT=		JetBrains IntelliJ IDEA Ultimate Edition
LICENSE=		apache-2.0

DEPENDS+=		intellij-fsnotifier-[0-9]*:../../sysutils/intellij-fsnotifier

WRKSRC=			${WRKDIR}/idea-IU-252.23892.409
USE_JAVA2=		17

USE_TOOLS+=		bash pax sed

REPLACE_BASH=		plugins/Kotlin/kotlinc/bin/kapt		\
			plugins/Kotlin/kotlinc/bin/kotlin	\
			plugins/Kotlin/kotlinc/bin/kotlinc	\
			plugins/Kotlin/kotlinc/bin/kotlinc-js	\
			plugins/Kotlin/kotlinc/bin/kotlinc-jvm	\
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
SUBST_STAGE.jdk=	pre-configure
SUBST_FILES.jdk=	bin/idea.sh
SUBST_VARS.jdk=		PKG_JAVA_HOME

SUBST_CLASSES+=		vmoptions
SUBST_STAGE.vmoptions=	pre-configure
SUBST_FILES.vmoptions=	bin/idea64.vmoptions
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
		bin/fsnotifier \
		lib/jna/*/libjnidispatch.so \
		lib/native/*/libsqliteij.so \
		lib/pty4j/linux/*/libpty.so \
		plugins/cwm-plugin/quiche-native/*/*.so \
		plugins/webp/lib/libwebp/linux/*.so \
		plugins/maven/lib/maven3/lib/jansi-native/Windows/*/*.dll \
		jbr

post-configure:
	${SED} -e "s|@@IDEA_HOME@@|${PREFIX}/${PKGBASE}|g" \
	    < ${FILESDIR}/idea-ultimate.desktop \
	    > ${WRKDIR}/idea-ultimate.desktop

do-build:
	${ECHO} "-XX:-UseCompressedClassPointers" \
	    >> ${WRKSRC}/bin/idea64.vmoptions
	${ECHO} "-XX:-UseCompressedOops" \
	    >> ${WRKSRC}/bin/idea64.vmoptions
	${ECHO} "idea.filewatcher.executable.path=${PREFIX}/bin/fsnotifier" \
	    >> ${WRKSRC}/bin/idea.properties
	# https://youtrack.jetbrains.com/issue/IDEA-323750
	${ECHO} "idea.ui.icons.svg.disk.cache=false" \
	    >> ${WRKSRC}/bin/idea.properties

do-install:
	${INSTALL_DATA} ${WRKDIR}/idea-ultimate.desktop \
	    ${DESTDIR}${PREFIX}/share/applications/
	cd ${WRKSRC} &&	pax -rw -pm -s ',.*\.orig,,' \
	    * ${DESTDIR}${PREFIX}/${PKGBASE}

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
