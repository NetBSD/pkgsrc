# $NetBSD: Makefile,v 1.2 2015/06/29 21:18:09 markd Exp $

.include "../../lang/swi-prolog-lite/Makefile.common"

PKGNAME=		swi-prolog-jpl-${SWIPLVERS}

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		jpl package for SWI Prolog

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake pkg-config
MAKE_JOBS_SAFE=		no

.include "../../mk/bsd.prefs.mk"

CONFIGURE_ENV+=		PL=swi-prolog
CONFIGURE_ENV+=		PLARCH=${MACHINE_GNU_PLATFORM}	# make PLIST consistent
CONFIGURE_ENV+=		PKG=jpl
CONFIGURE_ENV+=		JAVAC=${PKG_JAVA_HOME}/bin/javac

CONFIGURE_DIRS+=	. packages
BUILD_DIRS+=		packages/jpl
INSTALL_DIRS+=		packages/jpl
BUILD_TARGET=		libjpl.so jpl.jar

INSTALLATION_DIRS=	lib/swi-prolog-${PKGVERSION_NOREV}/bin/${MACHINE_GNU_PLATFORM}

TEST_TARGET=	check

pre-configure:
	${LN} -sf ${LOCALBASE}/bin/plld       ${WRKSRC}/src
	${LN} -sf ${LOCALBASE}/bin/swi-prolog ${WRKSRC}/src

post-configure:
	${LN} -sf ${LOCALBASE}/bin/plld       ${WRKSRC}/src
	${LN} -sf ${LOCALBASE}/bin/swi-prolog ${WRKSRC}/src
	cd ${WRKSRC}/packages; \
	${SETENV} \
		CPP=${CPP:Q} \
		${GMAKE} PKG=jpl configure
	mkdir ${WRKSRC}/include
	${LN} -sf ${WRKSRC}/src/SWI-Prolog.h ${WRKSRC}/include
	${LN} -sf ${WRKSRC}/src/os/SWI-Stream.h ${WRKSRC}/include


.include "../../lang/swi-prolog-lite/buildlink3.mk"
.include "../../mk/java-vm.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
# uses rl_event_hook() interface
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
