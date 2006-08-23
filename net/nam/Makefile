# $NetBSD: Makefile,v 1.21 2006/08/23 10:43:49 minskim Exp $

DISTNAME=	ns-allinone-2.29.3
PKGNAME=	nam-1.11
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=nsnam/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.isi.edu/nsnam/nam/
COMMENT=	The UCB/LBNL Network Animator

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=		${WRKDIR}/ns-allinone-2.29/nam-1.11
USE_LANGUAGES=	c c++
GNU_CONFIGURE=	yes
BUILD_TARGET=

CONFIGURE_ARGS+=	--with-tcl=${BUILDLINK_PREFIX.tcl}
CONFIGURE_ARGS+=	--with-tk=${BUILDLINK_PREFIX.tk}
CONFIGURE_ARGS+=	--with-otcl=${BUILDLINK_PREFIX.tcl-otcl}
CONFIGURE_ARGS+=	--with-tclcl=${BUILDLINK_PREFIX.tcl-tclcl}

CONFIGURE_ENV+=		V_LIBS="`${CONFIG_SHELL} -c '. ${TCLCONFIG_SH}; . ${TKCONFIG_SH}; ${ECHO} $$TCL_LIBS $$TK_LIBS'`"

MESSAGE_SUBST+=		HOMEPAGE=${HOMEPAGE}

INSTALLATION_DIRS=	bin

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/tcl-tclcl/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../lang/tcl-otcl/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"

post-install:
	${INSTALL_MAN_DIR} ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/nam.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
