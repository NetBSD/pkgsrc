# $NetBSD: Makefile,v 1.15 2004/12/25 19:46:30 wiz Exp $

DISTNAME=		rapidsvn-0.7.0
PKGREVISION=		1
CATEGORIES=		devel x11
MASTER_SITES=		http://www.rapidsvn.org/download/

MAINTAINER=		epg@NetBSD.org
HOMEPAGE=		http://rapidsvn.tigris.org/
COMMENT=		Cross-platform Subversion GUI

USE_BUILDLINK3=		YES
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES

CONFIGURE_ARGS+=	--with-svn-include=${BUILDLINK_DIR}/include
CONFIGURE_ARGS+=	--with-svn-lib=${BUILDLINK_DIR}/lib

INSTALLATION_DIRS+=	include/svncpp

.include "../../devel/apr/buildlink3.mk"
.include "../../devel/subversion/buildlink3.mk"
.include "../../x11/wxGTK/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
