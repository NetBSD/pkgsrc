# $NetBSD: Makefile,v 1.2 2002/08/28 10:09:54 seb Exp $

DISTNAME=	ns-src-2.1b9a
PKGNAME=	${DISTNAME:S/b/rc/:S/-src//}
CATEGORIES=	net
MASTER_SITES=	http://www.isi.edu/nsnam/dist/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.isi.edu/nsnam/ns/
COMMENT=	The UCB/LBNL Network Simulator Version 2

WRKSRC=		${WRKDIR}/${DISTNAME:S/-src//}

.include "../../mk/bsd.prefs.mk"

GNU_CONFIGURE=	yes
USE_BUILDLINK2=	yes
USE_X11=	yes
PTHREAD_OPTS+=		require
# Perl is only needed if you want to run the validation tests.
USE_PERL5=		build

CONFIGURE_ARGS+=	--with-tcl=${BUILDLINK_PREFIX.tcl}
CONFIGURE_ARGS+=	--with-tk=${BUILDLINK_PREFIX.tk}
CONFIGURE_ARGS+=	--with-tclcl=${BUILDLINK_PREFIX.tcl-tclcl}

MESSAGE_SUBST+=		HOMEPAGE=${HOMEPAGE}

# Yes there is object files and executables in the source tarball.
post-extract:
	${_PKG_SILENT}${_PKG_DEBUG}			\
	cd ${WRKSRC} &&					\
	${FIND} . -name "*.o" -exec ${RM} {} \;
	${_PKG_SILENT}${_PKG_DEBUG}			\
	cd ${WRKSRC}/indep-utils &&			\
	${RM} cmu-scen-gen/setdest/setdest		\
	   cmu-scen-gen/setdest/calcdest		\
	   webtrace-conv/dec/dec-tr-stat		\
	   webtrace-conv/epa/epa-tr-stat		\
	   webtrace-conv/nlanr/nlanr-tr-stat		\
	   webtrace-conv/ucb/ucb-tr-stat

.include  "../../net/libpcap/buildlink2.mk"
.include  "../../devel/tcl-tclcl/buildlink2.mk"
.include  "../../lang/tcl-otcl/buildlink2.mk"
.include "../../x11/tk/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
