# $NetBSD: Makefile,v 1.43 2017/07/28 07:46:45 tnn Exp $

DISTNAME=		synergy-1.8.8
CATEGORIES=		net x11
MASTER_SITES=		${MASTER_SITE_GITHUB:=symless/}
GITHUB_TAG=		v${PKGVERSION_NOREV}-stable

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://synergy-project.org/
COMMENT=		Let a user share a mouse and keyboard among computers
LICENSE=		gnu-gpl-v2

USE_LANGUAGES=		c c++11
USE_TOOLS+=		unzip
# Main configuration is CMake, but subdirectories are GNU configure.
# We need to set GNU_CONFIGURE=yes for config.{guess,sub} overrides to kick in.
# Fortunately for us, cmake seems to take precedence in infrastructure.
USE_CMAKE=		yes
GNU_CONFIGURE=		yes

CONFIG_SUB_OVERRIDE+=	ext/gmock-1.6.0/build-aux/config.sub
CONFIG_SUB_OVERRIDE+=	ext/gtest-1.6.0/build-aux/config.sub
CONFIG_GUESS_OVERRIDE+=	ext/gmock-1.6.0/build-aux/config.guess
CONFIG_GUESS_OVERRIDE+=	ext/gtest-1.6.0/build-aux/config.guess

EXAMPLES=	MacReadme.txt org.synergy-foss.org.synergyc.plist \
		org.synergy-foss.org.synergys.plist synergy.conf.example \
		synergy.conf.example-advanced synergy.conf.example-basic

SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		pre-configure
SUBST_MESSAGE.fix-paths=	Fixing absolute paths.
SUBST_FILES.fix-paths=		src/lib/arch/unix/ArchFileUnix.cpp
SUBST_FILES.fix-paths+=		src/lib/arch/unix/ArchDaemonUnix.h
SUBST_SED.fix-paths=		-e 's,"/etc,"${PKG_SYSCONFDIR},g'

BUILDLINK_TRANSFORM+=		rm:-march=native

post-extract:
	${MKDIR} ${WRKSRC}/ext/gmock-1.6.0
	cd ${WRKSRC}/ext/gmock-1.6.0 && unzip -aqo ../gmock-1.6.0.zip
	${MKDIR} ${WRKSRC}/ext/gtest-1.6.0
	cd ${WRKSRC}/ext/gtest-1.6.0 && unzip -aqo ../gtest-1.6.0.zip

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/examples/${PKGBASE}

do-install:
.for p in synergyc synergys
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${p} ${DESTDIR}${PREFIX}/bin/${p}
	${INSTALL_MAN} ${WRKSRC}/doc/${p}.man ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/${p}.1
.endfor
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/doc/${f} ${DESTDIR}${PREFIX}/share/examples/${PKGBASE}
.endfor

.include "../../mk/compiler.mk"
.if !empty(PKGSRC_COMPILER:Mclang)
_WRAP_EXTRA_ARGS.CXX+=	-Wno-switch -Wno-unused	\
			-Wno-deprecated-register -Wno-tautological-compare \
			-Wno-logical-op-parentheses -Wno-null-dereference
CWRAPPERS_APPEND.cxx+=	-Wno-switch -Wno-unused	\
			-Wno-deprecated-register -Wno-tautological-compare \
			-Wno-logical-op-parentheses -Wno-null-dereference
.endif

.include "../../mk/endian.mk"
.if ${MACHINE_ENDIAN} == "big"
CFLAGS+=	-DUSYNERGY_BIG_ENDIAN
.else
CFLAGS+=	-DUSYNERGY_LITTLE_ENDIAN
.endif

# XXX surely there exists a better way to do this
.if ${OPSYS} != "Linux"
BUILDLINK_TRANSFORM+=	rm:-ldl
.endif

.include "../../security/openssl/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.if !exists(/System/Library/Frameworks/Carbon.framework)
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.endif
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
