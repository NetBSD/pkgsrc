# $NetBSD: Makefile,v 1.16 2004/10/03 00:17:56 tv Exp $

DISTNAME=	ns-src-2.27
PKGNAME=	${DISTNAME:S/-src//}
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.isi.edu/nsnam/dist/

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.isi.edu/nsnam/ns/
COMMENT=	The UCB/LBNL Network Simulator Version 2

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=		${WRKDIR}/${DISTNAME:S/-src//}
USE_BUILDLINK3=	yes
USE_LANGUAGES=	c c++
GNU_CONFIGURE=	yes
USE_X11=	yes
PTHREAD_OPTS+=	require
# Perl is only needed if you want to run the validation tests.
#USE_PERL5=		build

CONFIGURE_ARGS+=	LIBS="`${CONFIG_SHELL} -c '. ${TCLCONFIG_SH}; echo $$TCL_LIBS'`"
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

# Remove a left over executable in the source tarball.
post-extract:
	${_PKG_SILENT}${_PKG_DEBUG}			\
	${RM} ${WRKSRC}/indep-utils/cmu-scen-gen/setdest/calcdest

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/ns
	${INSTALL_DATA} ${WRKSRC}/CHANGES.html ${PREFIX}/share/doc/html/ns

.include "../../mk/bsd.pkg.mk"
