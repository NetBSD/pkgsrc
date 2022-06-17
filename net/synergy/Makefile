# $NetBSD: Makefile,v 1.75 2022/06/17 18:09:24 tnn Exp $

DISTNAME=		synergy-core-1.14.4.37
PKGNAME=		${DISTNAME:S/-core//}
CATEGORIES=		net x11
MASTER_SITES=		${MASTER_SITE_GITHUB:=symless/}
GITHUB_PROJECT=		synergy-core
GITHUB_TAG=		v${PKGVERSION_NOREV}-stable
DISTFILES=		${DEFAULT_DISTFILES}		\
			  googletest-1.10.0.tar.gz	\
			  pugixml-1.12.1.tar.gz
SITES.googletest-1.10.0.tar.gz=	\
	-${MASTER_SITE_GITHUB:=google/}googletest/archive/release-1.10.0.tar.gz
SITES.pugixml-1.12.1.tar.gz=	\
	-${MASTER_SITE_GITHUB:=zeux/}pugixml/archive/v1.12.1.tar.gz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://synergy-project.org/
COMMENT=		Let a user share a mouse and keyboard among computers
LICENSE=		gnu-gpl-v2

USE_LANGUAGES=		c c++11
USE_CMAKE=		yes
USE_TOOLS+=		pkg-config
CMAKE_ARGS+=		-DSYNERGY_BUILD_LEGACY_GUI=OFF
CMAKE_ARGS+=		-DSYNERGY_BUILD_LEGACY_INSTALLER=OFF

CONFIGURE_ENV+=		GIT_COMMIT=218fa800

EXAMPLES=	MacReadme.txt org.synergy-foss.org.synergyc.plist \
		org.synergy-foss.org.synergys.plist synergy.conf.example \
		synergy.conf.example-advanced synergy.conf.example-basic

SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		pre-configure
SUBST_MESSAGE.fix-paths=	Fixing absolute paths.
SUBST_FILES.fix-paths=		src/lib/arch/unix/ArchFileUnix.cpp
SUBST_FILES.fix-paths+=		src/lib/arch/unix/ArchDaemonUnix.h
SUBST_SED.fix-paths=		-e 's,"/etc,"${PKG_SYSCONFDIR},g'

post-extract:
	${RM} -rf ${WRKSRC}/ext/googletest
	${LN} -s ${WRKDIR}/googletest-* ${WRKSRC}/ext/googletest
	${RM} -rf ${WRKSRC}/ext/pugixml
	${LN} -s ${WRKDIR}/pugixml-* ${WRKSRC}/ext/pugixml

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

LDFLAGS.SunOS+=	-lsocket -lnsl

.include "../../net/mDNSResponder/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.if !exists(/System/Library/Frameworks/Carbon.framework)
.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libxkbfile/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.endif
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
