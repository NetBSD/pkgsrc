# $NetBSD: Makefile,v 1.360 2026/02/26 13:38:43 ryoon Exp $

DISTNAME=	thunderbird-${TB_VER}.source
PKGNAME=	thunderbird-${TB_VER:S/esr//}
TB_VER=		148.0
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
WRKSRC=		${WRKDIR}/thunderbird-${TB_VER:C/b.*//}
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

#
# Generate list of subst entries for various .cargo-checksum.json files.  These
# are all handled together in one big substitution to simplify things rather
# than one substitution entry per file, but are kept separate below to ease
# updating and verification.
#

CKSUM_CRATES+=	comm/third_party/rust/minimal-lexical

# touch comm/third_party/rust/minimal-lexical/.gitmodules
CKSUMS+=	6976207a02c7160a3a1d076c5fae10fe4b78f58cdc0aa66ae47f3855b3c392fb
CKSUMS+=	e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855

CKSUM_CRATES+=	comm/third_party/rust/dogear

# patch-comm_third__party_rust_dogear_.github_workflows_upload-to-codecov.sh
CKSUMS+=	bb2cb096519bc76a5bb4fb217165686b27a6d08920d61dfc0a13d301fbe140c9
CKSUMS+=	61478eeb1ad8fface3596cedf42bfa4762da19ce84f2f1a33b9197bb93d35262

CKSUM_CRATES+=	comm/third_party/rust/sfv

# touch comm/third_party/rust/sfv/.gitmodules
CKSUMS+=	caa4f75b6a87c4a0f2e7d8d0d5fa2ef3f726fb0ae7797af09bfa3d57c4721148
CKSUMS+=	e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855

CKSUM_CRATES+=	comm/third_party/rust/glslopt

# touch comm/third_party/rust/glslopt/.gitmodules
CKSUMS+=	ffc0cce90e856d4f4bdb3bd3c950c9e59501a45ebd5022b91cfe8c07c79ef1ac
CKSUMS+=	e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855

SUBST_CLASSES+=		cksum
SUBST_STAGE.cksum=	pre-configure
.for crate in ${CKSUM_CRATES}
SUBST_FILES.cksum+=	${crate}/.cargo-checksum.json
.endfor
.for from to in ${CKSUMS}
SUBST_SED.cksum+=	-e 's,${from},${to},g'
.endfor

post-extract:
	${TOUCH} ${WRKSRC}/comm/third_party/rust/minimal-lexical/.gitmodules
	${TOUCH} ${WRKSRC}/comm/third_party/rust/sfv/.gitmodules
	${TOUCH} ${WRKSRC}/comm/third_party/rust/glslopt/.gitmodules
	#${CP} ${FILESDIR}/cubeb_sun.c ${WRKSRC}/media/libcubeb/src/cubeb_sun.c

pre-patch:
	for f in $$(find ${WRKSRC}/third_party/libwebrtc -name moz.build -type f) ; \
	do \
		${AWK} -f ${FILESDIR}/replace-moz.build.awk $$f > $$f.new; mv $$f.new $$f ; \
	done

pre-configure:
	cd ${WRKSRC} && mkdir -p ${OBJDIR}

do-build:
# XXX for some reason it doesn't work unless -j is explicitly specified
	${_ULIMIT_CMD} cd ${WRKSRC}/${OBJDIR} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} -j${_MAKE_JOBS_N:U1}

MOZILLA=	thunderbird
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
