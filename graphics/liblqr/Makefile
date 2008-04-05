# $NetBSD: Makefile,v 1.1.1.1 2008/04/05 02:00:39 tnn Exp $
#

DISTNAME=		liblqr-1-0.1.0-2
PKGNAME=		liblqr-0.1.0.2
CATEGORIES=		graphics
MASTER_SITES=		http://liblqr.wikidot.com/local--files/en:download-page/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://liblqr.wikidot.com/
COMMENT=		Content-aware image resizing library

PKG_DESTDIR_SUPPORT=	user-destdir
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config
USE_LIBTOOL=		yes
WRKSRC=			${WRKDIR}/liblqr-1-0.1.0
PKGCONFIG_OVERRIDE=	lqr-1.pc.in

.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
