# $NetBSD: Makefile,v 1.15 2004/04/27 04:59:42 snj Exp $

DISTNAME=		gcvs-1.0a7
PKGREVISION=		2
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=cvsgui/}

MAINTAINER=		mike@ethmoid.org
HOMEPAGE=		http://cvsgui.sourceforge.net/
COMMENT=		GTK interface for CVS

CONFLICTS=		cvs-[0-9]*

USE_BUILDLINK3=		yes
USE_X11=		yes
USE_GNU_TOOLS+=		make
GNU_CONFIGURE=		yes
USE_MAKEINFO=		yes
INFO_FILES=		cvs.info cvsclient.info

CONFIGURE_ARGS+=	--with-tclinclude="${BUILDLINK_PREFIX.tcl}/include" \
			--with-tcllib="${BUILDLINK_PREFIX.tcl}/lib"

.include "../../lang/tcl83/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
