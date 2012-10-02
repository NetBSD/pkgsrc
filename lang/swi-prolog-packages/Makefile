# $NetBSD: Makefile,v 1.33 2012/10/02 20:11:55 asau Exp $

.include "../../lang/swi-prolog-lite/Makefile.common"

PKGNAME=		swi-prolog-packages-${SWIPLVERS}
PKGREVISION=		2

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Packages for SWI Prolog

GNU_CONFIGURE=		yes
USE_GNU_READLINE=	yes	# uses rl_event_hook() interface
USE_TOOLS+=		gmake pkg-config
MAKE_JOBS_SAFE=		no

.include "../../mk/bsd.prefs.mk"

.if ${X11_TYPE} == "modular"
BUILD_DEPENDS+=		modular-xorg-server-[0-9]*:../../x11/modular-xorg-server
.endif

CONFIGURE_ENV+=		PL=swi-prolog
CONFIGURE_ENV+=		ARCH=${MACHINE_GNU_PLATFORM}	# make PLIST consistent
CONFIGURE_ARGS+=	--without-jpl

CONFIGURE_DIRS+=	. packages
BUILD_DIRS+=		packages
INSTALL_DIRS+=		packages

INSTALLATION_DIRS=	bin lib/swi-prolog-${PKGVERSION_NOREV}/bin/${MACHINE_GNU_PLATFORM} \
			lib/swi-prolog-${PKGVERSION_NOREV}/include ${PKGMANDIR}/man1

XPCE_VERSION=		6.6.66
PLIST_SUBST+=		XPCE_VERSION=${XPCE_VERSION}
# Help with PLIST:
PRINT_PLIST_AWK+=	{sub("${XPCE_VERSION}","$${XPCE_VERSION}")}

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
		${GMAKE} configure

pre-install: checkforx

# Based on misc/openoffice:
DISPLAY?=	#empty, if unset
checkforx:
.if ${DISPLAY} == "" || ${DISPLAY_OK:!${X11BASE}/bin/xdpyinfo >/dev/null 2>&1 && echo YES || echo NO!} == "NO"
.  if exists(${X11BASE}/bin/Xvfb)
	-${X11BASE}/bin/Xvfb :2 & \
	${ECHO} $$! >${WRKDIR}/.Xvfb.pid
	${ECHO} checkforx: Xvfb-PID: `${CAT} ${WRKDIR}/.Xvfb.pid`
	sleep 5
DISPLAY= :2
.  else
	@${ECHO} "Error: Environment variable DISPLAY must be set"
	@${ECHO} "       and point to a connectible X server."
	@${FALSE}
.  endif  #Xvfb
.endif  #DISPLAY

MAKE_ENV+=		DISPLAY=${DISPLAY:Q}

post-install: teardownx
	${RM} -f ${LOCALBASE}/lib/swi-prolog-${SWIPLVERS}/xpce-${XPCE_VERSION}/prolog/lib/.pwd
	${INSTALL_DATA} ${WRKSRC}/packages/xpce/man/xpce-client.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/xpce-client.1
	${INSTALL_DATA} ${WRKSRC}/packages/xpce/man/xpce.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/xpce.1
teardownx:
	${ECHO} teardownx: Xvfb-PID: `${CAT} ${WRKDIR}/.Xvfb.pid`
	sleep 5
	-kill `${CAT} ${WRKDIR}/.Xvfb.pid`
	${RM} -f ${WRKDIR}/.Xvfb.pid

# I need this on FreeBSD, perhaps this depends on GCC behaviour:
CHECK_WRKREF_SKIP=	lib/swi-prolog-${SWIPLVERS}/xpce-${XPCE_VERSION}/lib/${MACHINE_GNU_PLATFORM}/pl2xpce.so


.include "../../lang/swi-prolog-lite/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
