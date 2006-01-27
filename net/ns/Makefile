# $NetBSD: Makefile,v 1.22 2006/01/27 02:31:43 minskim Exp $

DISTNAME=	ns-src-2.29
PKGNAME=	${DISTNAME:S/-src//}
CATEGORIES=	net
MASTER_SITES=	http://www.isi.edu/nsnam/dist/

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.isi.edu/nsnam/ns/
COMMENT=	The UCB/LBNL Network Simulator Version 2

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=		${WRKDIR}/${DISTNAME:S/-src//}
USE_LANGUAGES=	c c++
GNU_CONFIGURE=	yes
PTHREAD_OPTS+=	require
# Perl is only needed if you want to run the validation tests.
#USE_TOOLS+=		perl

CONFIGURE_ARGS+=	LIBS="`${CONFIG_SHELL} -c '. ${TCLCONFIG_SH}; ${ECHO} $$TCL_LIBS'`"
CONFIGURE_ARGS+=	--with-tcl=${BUILDLINK_PREFIX.tcl}
CONFIGURE_ARGS+=	--with-tcl-ver=8.4
CONFIGURE_ARGS+=	--with-tk=${BUILDLINK_PREFIX.tk}
CONFIGURE_ARGS+=	--with-tk-ver=8.4
CONFIGURE_ARGS+=	--with-otcl=${BUILDLINK_PREFIX.tcl-otcl}
CONFIGURE_ARGS+=	--with-tclcl=${BUILDLINK_PREFIX.tcl-tclcl}

MESSAGE_SUBST+=		HOMEPAGE=${HOMEPAGE}

INSTALLATION_DIRS=	bin man/man1

.include "../../devel/tcl-tclcl/buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../lang/tcl-otcl/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/indep-utils/cmu-scen-gen/setdest/calcdest ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/indep-utils/webtrace-conv/dec/dec-tr-stat ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/indep-utils/webtrace-conv/epa/epa-tr-stat ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/indep-utils/webtrace-conv/nlanr/nlanr-tr-stat ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/indep-utils/cmu-scen-gen/setdest/setdest ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/indep-utils/webtrace-conv/ucb/ucb-tr-stat ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/ns
	${INSTALL_DATA} ${WRKSRC}/CHANGES.html ${PREFIX}/share/doc/ns

.include "../../mk/bsd.pkg.mk"
