# $NetBSD: Makefile,v 1.8 2004/01/20 12:22:20 agc Exp $

DISTNAME=	nam-src-1.9
PKGNAME=	${DISTNAME:S/-src//}
CATEGORIES=	net
MASTER_SITES=	http://www.isi.edu/nsnam/dist/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.isi.edu/nsnam/nam/
COMMENT=	The UCB/LBNL Network Animator

.include "../../mk/bsd.prefs.mk"

WRKSRC=		${WRKDIR}/${DISTNAME:S/-src//}
GNU_CONFIGURE=	yes
USE_BUILDLINK2=	yes
USE_X11=	yes
ALL_TARGET=

CONFIGURE_ARGS+=	--with-tcl=${BUILDLINK_PREFIX.tcl}
CONFIGURE_ARGS+=	--with-tk=${BUILDLINK_PREFIX.tk}
CONFIGURE_ARGS+=	--with-tclcl=${BUILDLINK_PREFIX.tcl-tclcl}

post-install:
	${INSTALL_MAN_DIR} ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/nam.1 ${PREFIX}/man/man1

.include  "../../devel/gettext-lib/buildlink2.mk"
.include  "../../devel/zlib/buildlink2.mk"
.include  "../../lang/tcl-otcl/buildlink2.mk"
.include  "../../devel/tcl-tclcl/buildlink2.mk"
.include "../../x11/tk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
