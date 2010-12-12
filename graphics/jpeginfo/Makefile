# $NetBSD: Makefile,v 1.8 2010/12/12 15:25:59 adam Exp $

DISTNAME=	jpeginfo-1.6.1
CATEGORIES=	graphics
MASTER_SITES=	http://www.kokkonen.net/tjko/src/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.kokkonen.net/tjko/projects.html
COMMENT=	Generates informative listings from JPEG files
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		autoconf
GNU_CONFIGURE=		yes

pre-configure:
	cd ${WRKSRC} && autoconf

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
