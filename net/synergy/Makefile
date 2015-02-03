# $NetBSD: Makefile,v 1.24 2015/02/03 19:08:55 tnn Exp $
#

DISTNAME=		synergy-1.6.2
CATEGORIES=		net x11
MASTER_SITES=		-https://github.com/synergy/synergy/archive/${PKGVERSION_NOREV}${EXTRACT_SUFX}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://synergy-project.org/
COMMENT=		Let a user share a mouse and keyboard among computers
LICENSE=		gnu-gpl-v2

EXTRACT_USING=		bsdtar
USE_LANGUAGES=		c c++
USE_TOOLS+=		unzip
USE_CMAKE=		yes

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
	${MKDIR} ${WRKSRC}/ext/cryptopp562
	cd ${WRKSRC}/ext/cryptopp562 && unzip -aqo ../cryptopp562.zip
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
_WRAP_EXTRA_ARGS.CXX+=	-std=c++11
CWRAPPERS_APPEND.cxx+=	-std=c++11
.endif

# tools/cryptopp562/GNUmakefile
.include "../../mk/bsd.prefs.mk"
.if !empty(MACHINE_PLATFORM:MNetBSD-[0-6].*-i386)
CXXFLAGS+=	-DCRYPTOPP_DISABLE_ASM
.endif

.include "../../www/curl/buildlink3.mk"
.if !exists(/System/Library/Frameworks/Carbon.framework)
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.endif
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
