# $NetBSD: Makefile,v 1.4 2003/07/17 21:34:08 grant Exp $

DISTNAME=	tclcl-src-1.0b12
PKGNAME=	tcl-${DISTNAME:S/b/rc/:S/-src//}
WRKSRC=		${WRKDIR}/${DISTNAME:S/-src//}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=otcl-tclcl/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://otcl-tclcl.sourceforge.net/tclcl/
COMMENT=	Tcl/C++ interface used by ns and nam

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_BUILDLINK2=		yes
USE_X11=		yes

CONFIGURE_ARGS+=	--with-tcl=${BUILDLINK_PREFIX.tcl}
CONFIGURE_ARGS+=	--with-tk=${BUILDLINK_PREFIX.tk}

CPPFLAGS+=	-I${BUILDLINK_PREFIX.tcl}/include/tcl/generic

.include  "../../lang/tcl-otcl/buildlink2.mk"
.include "../../x11/tk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
