# $NetBSD: Makefile,v 1.30 2012/12/15 22:17:31 markd Exp $

DISTNAME=	nam-src-1.15
PKGNAME=	nam-1.15
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=nsnam/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.isi.edu/nsnam/nam/
COMMENT=	The UCB/LBNL Network Animator

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
USE_LANGUAGES=	c c++
GNU_CONFIGURE=	yes
BUILD_TARGET=

CONFIGURE_ARGS+=	--with-tcl=${BUILDLINK_PREFIX.tcl}
CONFIGURE_ARGS+=	--with-tcl-ver=8.5
CONFIGURE_ARGS+=	--with-tk=${BUILDLINK_PREFIX.tk}
CONFIGURE_ARGS+=	--with-tk-ver=8.5
CONFIGURE_ARGS+=	--with-otcl=${BUILDLINK_PREFIX.tcl-otcl}
CONFIGURE_ARGS+=	--with-tclcl=${BUILDLINK_PREFIX.tcl-tclcl}

CONFIGURE_ENV+=		V_LIBS="`${CONFIG_SHELL} -c '. ${TCLCONFIG_SH}; . ${TKCONFIG_SH}; ${ECHO} $$TK_LIBS'`"

MESSAGE_SUBST+=		HOMEPAGE=${HOMEPAGE}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/tcl-tclcl/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../lang/tcl-otcl/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"

post-install:
	${INSTALL_MAN} ${WRKSRC}/nam.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
