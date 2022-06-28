# $NetBSD: Makefile,v 1.55 2022/06/28 11:35:04 wiz Exp $

DISTNAME=	ns-src-2.35
PKGNAME=	ns-2.35
PKGREVISION=	12
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=nsnam/}

MAINTAINER=	minskim@NetBSD.org
#HOMEPAGE=	http://nsnam.isi.edu/nsnam/
COMMENT=	The UCB/LBNL Network Simulator Version 2

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
USE_LANGUAGES=	c99 c++
USE_TOOLS+=	gmake
GNU_CONFIGURE=	yes
PTHREAD_OPTS+=	require
# Perl is only needed if you want to run the validation tests.
#USE_TOOLS+=	perl
TOOLS_BROKEN+=	perl

CONFIGURE_ARGS+=	LIBS="`${CONFIG_SHELL} -c '. ${TCLCONFIG_SH}; ${ECHO} $$TCL_LIBS'`"
CONFIGURE_ARGS+=	--with-tcl=${BUILDLINK_PREFIX.tcl}
CONFIGURE_ARGS+=	--with-tcl-ver=8.6
CONFIGURE_ARGS+=	--with-tk=${BUILDLINK_PREFIX.tk}
CONFIGURE_ARGS+=	--with-tk-ver=8.6
CONFIGURE_ARGS+=	--with-otcl=${BUILDLINK_PREFIX.tcl-otcl}
CONFIGURE_ARGS+=	--with-tclcl=${BUILDLINK_PREFIX.tcl-tclcl}
CONFIGURE_ENV+=		X11LIBDIR=${X11BASE}/lib${LIBABISUFFIX}
CONFIGURE_ENV+=		X11INCDIR=${X11BASE}/include

SUBST_CLASSES+=		char
SUBST_STAGE.char=	pre-configure
SUBST_MESSAGE.char=	unsigned char needed for 8bit values
SUBST_FILES.char=	bitmap/*.xbm
SUBST_SED.char=		-e 's,char,u_char,'

MESSAGE_SUBST+=		HOMEPAGE=${HOMEPAGE}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/doc/ns

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/indep-utils/cmu-scen-gen/setdest/calcdest ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/indep-utils/webtrace-conv/dec/dec-tr-stat ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/indep-utils/webtrace-conv/epa/epa-tr-stat ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/indep-utils/webtrace-conv/nlanr/nlanr-tr-stat ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/indep-utils/cmu-scen-gen/setdest/setdest ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/indep-utils/webtrace-conv/ucb/ucb-tr-stat ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/CHANGES.html ${DESTDIR}${PREFIX}/share/doc/ns

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../devel/tcl-tclcl/buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../lang/tcl-otcl/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
