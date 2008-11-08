# $NetBSD: Makefile,v 1.34 2008/11/08 18:50:56 heinz Exp $
#

DISTNAME=		xdelta-1.1.4
CATEGORIES=		devel
MASTER_SITES=		http://xdelta.googlecode.com/files/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://xdelta.org/
COMMENT=		Enhanced diff that works on binary files

PKG_DESTDIR_SUPPORT=	user-destdir

BUILDLINK_API_DEPENDS.glib+=	glib>=1.2.8
BUILDLINK_API_DEPENDS.zlib+=	zlib>=1.1.3
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
INFO_FILES=		# PLIST

.include "../../devel/glib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
