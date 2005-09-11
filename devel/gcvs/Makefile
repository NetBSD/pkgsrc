# $NetBSD: Makefile,v 1.21 2005/09/11 13:59:38 adrianp Exp $

DISTNAME=		gcvs-1.0
PKGREVISION=		2
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=cvsgui/}
# extra distfile containing an updated configure script
DISTFILES=		${DISTNAME}${EXTRACT_SUFX} gcvs-1.0-configure.tar.gz

MAINTAINER=		mike@ethmoid.org
HOMEPAGE=		http://cvsgui.sourceforge.net/
COMMENT=		GTK interface for CVS

CONFLICTS=		cvs-[0-9]*

USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
USE_MAKEINFO=		yes
INFO_FILES=		cvs.info cvsclient.info

CONFIGURE_ARGS+=	--with-tclinclude="${BUILDLINK_PREFIX.tcl}/include" \
			--with-tcllib="${BUILDLINK_PREFIX.tcl}/lib"

.include "../../lang/tcl/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
