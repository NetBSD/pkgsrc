# $NetBSD: Makefile,v 1.3 2004/10/03 00:15:02 tv Exp $

.include "../swi-prolog-lite/Makefile.common"

PKGNAME=		swi-prolog-packages-${SWIPLVERS}
PKGREVISION=	1

MAINTAINER=		hubertf@NetBSD.org
COMMENT=		Packages for SWI Prolog

GNU_CONFIGURE=		yes
USE_BUILDLINK3=		yes
USE_GNU_READLINE=	yes	# uses rl_event_hook() interface
USE_GNU_TOOLS+=		make
USE_X11=		yes

CONFIGURE_ENV+=		PL=swi-prolog
CONFIGURE_ARGS+=	--disable-mt

BUILD_DIRS+=		${WRKSRC}/packages
INSTALL_DIRS+=		${WRKSRC}/packages

.include "../../mk/bsd.prefs.mk"

post-configure:
	cd ${WRKSRC}/packages; \
	${SETENV} \
		CPP=${CPP} \
		gmake configure

pre-build:
	${LN} -sf ${LOCALBASE}/bin/plld       ${WRKSRC}/src
	${LN} -sf ${LOCALBASE}/bin/swi-prolog ${WRKSRC}/src

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

MAKE_ENV+=		DISPLAY=${DISPLAY}

post-install: teardownx
teardownx:
	${ECHO} teardownx: Xvfb-PID: `${CAT} ${WRKDIR}/.Xvfb.pid`
	sleep 5
	-kill `${CAT} ${WRKDIR}/.Xvfb.pid`
	rm -f ${WRKDIR}/.Xvfb.pid


.include "../../lang/swi-prolog-lite/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/xpm/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
#.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
