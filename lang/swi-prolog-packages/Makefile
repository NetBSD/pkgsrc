# $NetBSD: Makefile,v 1.13 2006/08/29 23:58:24 markd Exp $

.include "../../lang/swi-prolog-lite/Makefile.common"

PKGNAME=		swi-prolog-packages-${SWIPLVERS}
PKGREVISION=		1

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Packages for SWI Prolog

GNU_CONFIGURE=		yes
USE_GNU_READLINE=	yes	# uses rl_event_hook() interface
USE_TOOLS+=		gmake

CONFIGURE_ENV+=		PL=swi-prolog
CONFIGURE_ARGS+=	--disable-mt

BUILD_DIRS+=		${WRKSRC}/packages
INSTALL_DIRS+=		${WRKSRC}/packages

.include "../../mk/bsd.prefs.mk"

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
	${RM} -f ${LOCALBASE}/lib/swi-prolog-${SWIPLVERS}/xpce-6.6.17/prolog/lib/.pwd
teardownx:
	${ECHO} teardownx: Xvfb-PID: `${CAT} ${WRKDIR}/.Xvfb.pid`
	sleep 5
	-kill `${CAT} ${WRKDIR}/.Xvfb.pid`
	${RM} -f ${WRKDIR}/.Xvfb.pid


.include "../../lang/swi-prolog-lite/buildlink3.mk"
.include "../../fonts/Xft2/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/xpm/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
#.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
