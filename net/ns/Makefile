# $NetBSD: Makefile,v 1.27 2006/08/23 10:28:06 minskim Exp $

DISTNAME=	ns-allinone-2.29.3
PKGNAME=	${DISTNAME:S/-allinone//}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=nsnam/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://nsnam.isi.edu/nsnam/
COMMENT=	The UCB/LBNL Network Simulator Version 2

PKG_INSTALLATION_TYPES=	overwrite pkgviews

BUILDLINK_API_DEPENDS.tcl+=	tcl>=8.4.12nb1
BUILDLINK_API_DEPENDS.tk+=	tk>=8.4.12nb2

WRKSRC=		${WRKDIR}/ns-allinone-2.29/ns-2.29
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
