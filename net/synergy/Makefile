# $NetBSD: Makefile,v 1.12 2011/01/23 02:26:58 tnn Exp $
#

DISTNAME=		synergy-1.3.6-Source
PKGNAME=		${DISTNAME:S/-Source//}
CATEGORIES=		net x11
MASTER_SITES=		http://synergy.googlecode.com/files/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://synergy-foss.org/
COMMENT=		Let a user share a mouse and keyboard among computers

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++

# Below rpath fix is copypasted from graphics/vtk.
CMAKE_OPTS+=	-DCMAKE_INSTALL_RPATH:STRING=${PREFIX}/lib:${X11BASE}/lib${LIBABISUFFIX:Q}	\
CMAKE_OPTS+=	-DCMAKE_SKIP_BUILD_RPATH:BOOL=ON		\
CMAKE_OPTS+=	-DCMAKE_BUILD_WITH_INSTALL_RPATH:BOOL=ON	\
CMAKE_OPTS+=	-DCMAKE_INSTALL_RPATH_USE_LINK_PATH:BOOL=ON

SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		pre-configure
SUBST_MESSAGE.fix-paths=	Fixing absolute paths.
SUBST_FILES.fix-paths=		lib/arch/CArchFileUnix.cpp
SUBST_SED.fix-paths=		-e 's,"/etc","${PKG_SYSCONFDIR}",g'

do-configure:
	cd ${WRKSRC} && ${PREFIX}/bin/cmake ${CMAKE_OPTS} .

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/examples/${PKGBASE}

post-build:
	${CP} ${WRKSRC}/doc/synergyc.man ${WRKSRC}/doc/synergyc.1
	${CP} ${WRKSRC}/doc/synergys.man ${WRKSRC}/doc/synergys.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/synergyc ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/synergys ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/synergyc.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/doc/synergys.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/doc/*.conf ${DESTDIR}${PREFIX}/share/examples/${PKGBASE}

.include "../../devel/cmake/buildlink3.mk"
.if !exists(/System/Library/Frameworks/Carbon.framework)
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.endif
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
