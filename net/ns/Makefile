# $NetBSD: Makefile,v 1.44 2014/02/01 08:04:04 markd Exp $

DISTNAME=	ns-src-2.35
PKGNAME=	ns-2.35
PKGREVISION=	7
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=nsnam/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://nsnam.isi.edu/nsnam/
COMMENT=	The UCB/LBNL Network Simulator Version 2

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
USE_LANGUAGES=	c99 c++
USE_TOOLS+=	gmake
GNU_CONFIGURE=	yes
PTHREAD_OPTS+=	require
# Perl is only needed if you want to run the validation tests.
#USE_TOOLS+=		perl

CONFIGURE_ARGS+=	LIBS="`${CONFIG_SHELL} -c '. ${TCLCONFIG_SH}; ${ECHO} $$TCL_LIBS'`"
CONFIGURE_ARGS+=	--with-tcl=${BUILDLINK_PREFIX.tcl}
CONFIGURE_ARGS+=	--with-tcl-ver=8.6
CONFIGURE_ARGS+=	--with-tk=${BUILDLINK_PREFIX.tk}
CONFIGURE_ARGS+=	--with-tk-ver=8.6
CONFIGURE_ARGS+=	--with-otcl=${BUILDLINK_PREFIX.tcl-otcl}
CONFIGURE_ARGS+=	--with-tclcl=${BUILDLINK_PREFIX.tcl-tclcl}
CONFIGURE_ENV+=		X11LIBDIR=${X11PREFIX}/lib${LIBABISUFFIX}
CONFIGURE_ENV+=		X11INCDIR=${X11PREFIX}/include

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
