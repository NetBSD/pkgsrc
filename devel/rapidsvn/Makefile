# $NetBSD: Makefile,v 1.9 2004/02/14 17:21:39 jlam Exp $

DISTNAME=		rapidsvn-0.5.0
CATEGORIES=		devel x11
MASTER_SITES=		http://www.rapidsvn.org/download/

MAINTAINER=		epg@NetBSD.org
HOMEPAGE=		http://rapidsvn.tigris.org/
COMMENT=		Cross-platform Subversion GUI

USE_BUILDLINK2=		YES
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES

CONFIGURE_ARGS+=	--with-svn-include=${BUILDLINK_DIR}/include
CONFIGURE_ARGS+=	--with-svn-lib=${BUILDLINK_DIR}/lib

BUILDLINK_DEPENDS.subversion-base=	subversion-base>=0.36.0
BUILDLINK_DEPENDS.wxGTK=	wxGTK>=2.4.0

.include "../../devel/apr/buildlink2.mk"
.include "../../devel/subversion/buildlink2.mk"
.include "../../x11/wxGTK/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
