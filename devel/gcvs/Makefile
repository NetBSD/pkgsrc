# $NetBSD: Makefile,v 1.8 2002/09/21 10:26:44 jlam Exp $

DISTNAME=		gcvs-1.0a7
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=cvsgui/}

MAINTAINER=		mike@ethmoid.org
HOMEPAGE=		http://cvsgui.sourceforge.net/
COMMENT=		GTK interface for CVS

CONFLICTS=		cvs-[0-9]*

USE_BUILDLINK2=		yes
USE_X11=		yes
USE_GMAKE=		yes
GNU_CONFIGURE=		yes
TEXINFO_OVERRIDE=	YES

CONFIGURE_ARGS+=	--with-tclinclude="${BUILDLINK_PREFIX.tcl}/include" \
			--with-tcllib="${BUILDLINK_PREFIX.tcl}/lib"

.include "../../lang/tcl/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
