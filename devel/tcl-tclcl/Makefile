# $NetBSD: Makefile,v 1.39 2023/11/12 13:21:12 wiz Exp $

DISTNAME=	tclcl-src-1.20
PKGNAME=	tcl-${DISTNAME:S/-src//}
PKGREVISION=	5
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=otcl-tclcl/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://otcl-tclcl.sourceforge.net/tclcl/
COMMENT=	Tcl/C++ interface used by ns and nam

WRKSRC=		${WRKDIR}/${DISTNAME:S/-src//}
USE_LANGUAGES=	c c++
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

# Fails with C++14 default language.
FORCE_CXX_STD=	c++03

CONFIGURE_ARGS+=	--with-tcl=${BUILDLINK_PREFIX.tcl}
CONFIGURE_ARGS+=	--with-tk=${BUILDLINK_PREFIX.tk}
CONFIGURE_ARGS+=	--with-otcl=${BUILDLINK_PREFIX.tcl-otcl}

CPPFLAGS+=	-I${BUILDLINK_PREFIX.tcl}/include/tcl/generic

INSTALLATION_DIRS=	bin include lib

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../lang/tcl/Makefile.version"
.include "../../x11/tk/Makefile.version"

CONFIGURE_ARGS+=	--with-tcl-ver=${TCL_VERSION}
CONFIGURE_ARGS+=	--with-tk-ver=${TK_VERSION}

.include "../../lang/tcl/buildlink3.mk"
.include "../../lang/tcl-otcl/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
