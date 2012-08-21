# $NetBSD: Makefile,v 1.20 2012/08/21 23:49:20 marino Exp $

DISTNAME=	tclcl-src-1.19
PKGNAME=	tcl-${DISTNAME:S/-src//}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=otcl-tclcl/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://otcl-tclcl.sourceforge.net/tclcl/
COMMENT=	Tcl/C++ interface used by ns and nam

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/${DISTNAME:S/-src//}
USE_LANGUAGES=	c c++
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

CONFIGURE_ARGS+=	--with-tcl=${BUILDLINK_PREFIX.tcl}
CONFIGURE_ARGS+=	--with-tk=${BUILDLINK_PREFIX.tk}
CONFIGURE_ARGS+=	--with-otcl=${BUILDLINK_PREFIX.tcl-otcl}

CPPFLAGS+=	-I${BUILDLINK_PREFIX.tcl}/include/tcl/generic

INSTALLATION_DIRS=	bin include lib

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../lang/tcl/buildlink3.mk"
.include "../../lang/tcl-otcl/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
