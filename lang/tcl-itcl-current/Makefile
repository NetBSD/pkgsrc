# $NetBSD: Makefile,v 1.3 2004/10/07 16:21:38 tv Exp $

DISTNAME=	tcl-itcl-20040920
PKGNAME=	${DISTNAME:S/itcl/itcl-current/}
PKGREVISION=	2
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
