# $NetBSD: Makefile,v 1.5 2003/07/13 13:52:57 wiz Exp $

DISTNAME=	nam-src-1.0a11a
PKGNAME=	${DISTNAME:S/0a/0rc/:S/-src//}
PKGREVISION=			1
WRKSRC=		${WRKDIR}/${DISTNAME:S/-src//}
CATEGORIES=	net
MASTER_SITES=	http://www.isi.edu/nsnam/dist/

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://www.isi.edu/nsnam/nam/
COMMENT=	The UCB/LBNL Network Animator

.include "../../mk/bsd.prefs.mk"

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
