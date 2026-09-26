# $NetBSD: Makefile,v 1.370 2026/09/26 07:45:51 ryoon Exp $

DISTNAME=	thunderbird-${TB_VER}.source
PKGNAME=	thunderbird-${TB_VER:S/esr//}
TB_VER=		156.0.1
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_MOZILLA:=thunderbird/releases/${TB_VER}/source/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.thunderbird.net/en-US/
COMMENT=	Organize, secure and customize your mail
LICENSE=	mpl-1.1

# As of 2023-08 on netbsd-10 amd64, this package required 22G of space
# in WRKDIR (noted because it is egregiously and unexpectedly large,
# overflowing even a biggish tmpfs).

USE_TOOLS+=	unzip pax
WRKSRC=		${WRKDIR}/thunderbird-${TB_VER:C/b.*//:S/esr//}
MOZILLA_DIR=	# empty
PLIST_SRC+=	${PLIST_SRC_DFLT}

DEPENDS+=	libotr-[0-9]*:../../chat/libotr

ALL_ENV+=	MOZ_APP_NAME=${MOZILLA}

CONFIG_GUESS_OVERRIDE+=	comm/ldap/sdks/c-sdk/config/autoconf/config.guess
CONFIG_SUB_OVERRIDE+=	comm/ldap/sdks/c-sdk/config/autoconf/config.sub

CONFIGURE_ARGS+=	--enable-application=comm/mail
CONFIGURE_ARGS+=	--enable-webrtc
CONFIGURE_ARGS+=	--with-app-name=${MOZILLA}

NOT_PAX_MPROTECT_SAFE+=	lib/${MOZILLA_NAME}/${MOZILLA_NAME}
NOT_PAX_MPROTECT_SAFE+=	lib/${MOZILLA_NAME}/${MOZILLA_NAME}-bin

# Do not use uselocale() in third_party/pipewire.
CFLAGS.NetBSD+=	-D__LOCALE_C_ONLY

LDFLAGS+=		${COMPILER_RPATH_FLAG}${PREFIX}/lib/${MOZILLA_NAME}

# Workaround for https://bugs.llvm.org/show_bug.cgi?id=46366
BUILDLINK_TRANSFORM.NetBSD+=	rm:-fexperimental-new-pass-manager

BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,-rpath-link,${WRKDIR}/build/dist/bin
BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,-rpath-link,${PREFIX}/lib

.include "../../mk/bsd.prefs.mk"

CHECK_WRKREF_SKIP+=	lib/${MOZILLA_NAME}/omni.ja

PRINT_PLIST_AWK+=	/\/${MOZILLA}\// { gsub(/\/${MOZILLA}\//, "/$${MOZILLA}/") }
PRINT_PLIST_AWK+=	/\/${MOZILLA}.png$$/ { gsub(/\/${MOZILLA}.png$$/, "/$${MOZILLA}.png") }
PRINT_PLIST_AWK+=	/\/${MOZILLA}.desktop$$/ { gsub(/\/${MOZILLA}.desktop$$/, "/$${MOZILLA}.desktop") }
PRINT_PLIST_AWK+=	/\/${MOZILLA}$$/ { gsub(/\/${MOZILLA}$$/, "/$${MOZILLA}") }
PRINT_PLIST_AWK+=	/\/${MOZILLA}-bin$$/ { gsub(/\/${MOZILLA}-bin$$/, "/$${MOZILLA}-bin") }
PLIST_SUBST+=		MOZILLA=${MOZILLA}

post-extract:
	#${TOUCH} ${WRKSRC}/comm/third_party/rust/minimal-lexical/.gitmodules
	#${TOUCH} ${WRKSRC}/comm/third_party/rust/sfv/.gitmodules
	#${TOUCH} ${WRKSRC}/comm/third_party/rust/glslopt/.gitmodules
	#${CP} ${FILESDIR}/cubeb_sun.c ${WRKSRC}/media/libcubeb/src/cubeb_sun.c

pre-patch:
	for f in $$(find ${WRKSRC}/third_party/libwebrtc -name moz.build -type f) ; \
	do \
		${AWK} -f ${FILESDIR}/replace-moz.build.awk $$f > $$f.new; mv $$f.new $$f ; \
	done
	for f in $$(find ${WRKSRC}/third_party/abseil-cpp -name moz.build -type f) ; \
	do \
		${AWK} -f ${FILESDIR}/replace-moz.build.awk $$f > $$f.new; mv $$f.new $$f ; \
	done

pre-configure:
	cd ${WRKSRC} && mkdir -p ${OBJDIR}

do-build:
# XXX for some reason it doesn't work unless -j is explicitly specified
	${_ULIMIT_CMD} cd ${WRKSRC}/${OBJDIR} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} -j${_MAKE_JOBS_N:U1}

MOZILLA=	${PKGBASE}
MOZILLA_NAME=	${PKGBASE}
post-build:
	${SED} -e 's|@MOZILLA@|${MOZILLA}|g'				\
	  -e 's|@MOZILLA_NAME@|${MOZILLA_NAME}|g'			\
	  -e 's|@MOZILLA_ICON@|${MOZILLA_NAME}.png|g'			\
	  < ${FILESDIR}/desktop.in					\
	  > ${WRKDIR}/desktop

INSTALLATION_DIRS+=	lib/${MOZILLA_NAME}/extensions
INSTALLATION_DIRS+=	share/applications share/pixmaps
post-install:
	${ECHO} '#! /bin/sh' > ${DESTDIR}${PREFIX}/bin/${MOZILLA_NAME}
	${ECHO} '${PREFIX}/lib/${MOZILLA_NAME}/${MOZILLA_NAME} "$$@"' >> \
		${DESTDIR}${PREFIX}/bin/${MOZILLA_NAME}
	${CHMOD} 755 ${DESTDIR}${PREFIX}/bin/${MOZILLA_NAME}
	${INSTALL_DATA} ${WRKDIR}/desktop				\
	  ${DESTDIR}${PREFIX}/share/applications/${MOZILLA_NAME}.desktop
	${INSTALL_DATA} ${WRKSRC}/${OBJDIR}/dist/${MOZILLA_NAME}/chrome/icons/default/default48.png	\
	  ${DESTDIR}${PREFIX}/share/pixmaps/${MOZILLA_NAME}.png

.include "mozilla-common.mk"
.include "options.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
