# $NetBSD: Makefile,v 1.9 2003/10/06 11:02:45 jlam Exp $

DISTNAME=	ns-src-2.26
PKGNAME=	${DISTNAME:S/-src//}
PKGREVISION=	1
WRKSRC=		${WRKDIR}/${DISTNAME:S/-src//}
CATEGORIES=	net
MASTER_SITES=	http://www.isi.edu/nsnam/dist/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.isi.edu/nsnam/ns/
COMMENT=	The UCB/LBNL Network Simulator Version 2

.include "../../mk/bsd.prefs.mk"

GNU_CONFIGURE=	yes
USE_BUILDLINK2=	yes
USE_X11=	yes
PTHREAD_OPTS+=		require
# Perl is only needed if you want to run the validation tests.
#USE_PERL5=		build

CONFIGURE_ARGS+=	--with-tcl=${BUILDLINK_PREFIX.tcl}
CONFIGURE_ARGS+=	--with-tk=${BUILDLINK_PREFIX.tk}
CONFIGURE_ARGS+=	--with-tclcl=${BUILDLINK_PREFIX.tcl-tclcl}

MESSAGE_SUBST+=		HOMEPAGE=${HOMEPAGE}

# Remove a left over executable in the source tarball.
post-extract:
	${_PKG_SILENT}${_PKG_DEBUG}			\
	${RM} ${WRKSRC}/indep-utils/cmu-scen-gen/setdest/calcdest

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/ns
	${INSTALL_DATA} ${WRKSRC}/CHANGES.html ${PREFIX}/share/doc/html/ns

.include  "../../net/libpcap/buildlink2.mk"
.include  "../../devel/tcl-tclcl/buildlink2.mk"
.include  "../../lang/tcl-otcl/buildlink2.mk"
.include "../../x11/tk/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
