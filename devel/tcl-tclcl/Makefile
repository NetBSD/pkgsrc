# $NetBSD: Makefile,v 1.10 2005/02/14 04:40:49 minskim Exp $

DISTNAME=	tclcl-src-1.16
PKGNAME=	tcl-${DISTNAME:S/-src//}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=otcl-tclcl/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://otcl-tclcl.sourceforge.net/tclcl/
COMMENT=	Tcl/C++ interface used by ns and nam

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=		${WRKDIR}/${DISTNAME:S/-src//}
USE_BUILDLINK3=	yes
USE_LANGUAGES=	c c++
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_X11=	yes

CONFIGURE_ARGS+=	--with-tcl=${BUILDLINK_PREFIX.tcl}
CONFIGURE_ARGS+=	--with-tk=${BUILDLINK_PREFIX.tk}
CONFIGURE_ARGS+=	--with-otcl=${BUILDLINK_PREFIX.tcl-otcl}

CPPFLAGS+=	-I${BUILDLINK_PREFIX.tcl}/include/tcl/generic

INSTALLATION_DIRS=	bin include lib

.include "../../lang/tcl/buildlink3.mk"
.include "../../lang/tcl-otcl/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
