# $NetBSD: Makefile,v 1.1.1.1 2004/09/24 21:16:02 dmcmahill Exp $

DISTNAME=	tcl-itcl-20040920
PKGNAME=	${DISTNAME:S/itcl/itcl-current/}
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://tcltk.com/itcl/
COMMENT=	[incr Tcl] object-oriented extension to Tcl/Tk.  CVS snapshot

PKG_INSTALLATION_TYPES=	overwrite pkgviews

CONFLICTS+=	tcl-itcl-[0-9]*

WRKSRC=		${WRKDIR}/tcl-itcl-3.3
USE_BUILDLINK3=	yes
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
CONFIGURE_ARGS= --with-tcl=${BUILDLINK_PREFIX.tcl}/lib	\
		--with-tk=${BUILDLINK_PREFIX.tk}/lib	\
		--enable-shared

MAKE_ENV+=	TCL_HEADER_DIR=${BUILDLINK_PREFIX.tcl}/include/tcl

.include "../../lang/tcl/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
