# $NetBSD: Makefile,v 1.1.1.1 2003/12/07 04:09:22 epg Exp $

DISTNAME=		rapidsvn-0.4.0
CATEGORIES=		devel x11
MASTER_SITES=	http://rapidsvn.tigris.org/files/documents/341/8734/

MAINTAINER=		epg@NetBSD.org
HOMEPAGE=		http://rapidsvn.tigris.org/
COMMENT=		Cross-platform Subversion GUI

USE_BUILDLINK2=	YES
USE_GMAKE=		YES
USE_LIBTOOL=		YES

GNU_CONFIGURE=	YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

CONFIGURE_ARGS+=	--with-svn-include=${BUILDLINK_DIR}/include
CONFIGURE_ARGS+=	--with-svn-lib=${BUILDLINK_DIR}/lib

BUILDLINK_DEPENDS.wxGTK=	wxGTK>=2.4.0

.include "../../devel/apr/buildlink2.mk"
.include "../../devel/subversion/buildlink2.mk"
.include "../../x11/wxGTK/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
